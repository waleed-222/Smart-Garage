using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace CI_Project
{
    public partial class Form1 : Form
    {
        int free = 99, used = 0;
        bool checkIn=false,checkOut=false;
        SerialPort port = null;

        private string data_rx = "";
        private bool start_Receive = false;

        private const int BAUD_RATE = 9600;
        private const int DATA_BITS = 8;

        private const String STATUS_CONNECTED = "Connected with port: ";
        private const String STATUS_DISCONNECTED = "Disconnected";

        public Form1()
        {
            InitializeComponent();
            refresh();


        

        }

        private void port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sPort = (SerialPort)sender;
            // Show all the incoming data in the port's buffer
            string dataRecieved = sPort.ReadExisting();
            if (dataRecieved.Contains("I"))
            {
                checkIn = true;
                label4.Invoke((Action)(() =>
                {
                    label4.Text = "A car wants to Enter";
                    label4.ForeColor = Color.Green;
                }));
            }
            else if (dataRecieved.Contains("O"))
            {
                checkOut = true;
                label5.Invoke((Action)(() =>
                {
                    label5.Text = "A car wants to Exit";
                    label5.ForeColor = Color.Red;
                }));
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (port.IsOpen)
            {
                send("y");
                enter();
                label4.Invoke((Action)(() =>
                {
                    label4.Text = "";
                }));
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (port.IsOpen)
            {
                send("y");
                leave();
                label5.Invoke((Action)(() =>
                {
                    label5.Text = "";
                }));
            }
        }

        private void enter()
        {
            if(used != 99 && checkIn)
            {
                free--; used++;checkIn = false;
            }
            label1.Text = "Remaining Cars: " + used.ToString();
            label2.Text = "Free Slots: " + free.ToString();
        }

        private void leave()
        {
            if(used != 0 && checkOut)
            {
                free++; used--;checkOut = false;
            }
            label1.Text = "Remaining Cars: " + used.ToString();
            label2.Text = "Free Slots: " + free.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            port = new SerialPort(comboBox1.SelectedItem.ToString());
            initConfig();
            connect();
        }

        private void initConfig()
        {
            port.StopBits = StopBits.One;
            port.BaudRate = BAUD_RATE;
            port.DataBits = DATA_BITS;
            /* serialPort.Parity = Parity.Even; */
        }



        private void connect()
        {
            try
            {
                if (!port.IsOpen)
                {
                    port.Open();
                    port.DataReceived += new SerialDataReceivedEventHandler(port_DataReceived);
                    label3.Text = STATUS_CONNECTED + comboBox1.SelectedItem.ToString();
                    label3.ForeColor = Color.Green;
                }
            }
            catch (Exception e)
            {

            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            refresh();
        }

        private void refresh()
        {
            comboBox1.DataSource = SerialPort.GetPortNames();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            disconnect();
        }

        private void disconnect()
        {
            if (port == null)
            {
                return;
            }
            try
            {
                if (port.IsOpen)
                {
                    port.Close();
                    label3.Text = STATUS_DISCONNECTED;
                    label3.ForeColor = Color.Red;
                }
            }
            catch (Exception e)
            {

            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (port.IsOpen)
            {
                send("n");
                label4.Invoke((Action)(() =>
                {
                    label4.Text = "";
                }));

            }
        }

        private void send(String data)
        {
            try
            {
                if (port != null)
                {
                    port.Write(data);
                }
            }
            catch (Exception)
            {

            }
        }


    }
}
