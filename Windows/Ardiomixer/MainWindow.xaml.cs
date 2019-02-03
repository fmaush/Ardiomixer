using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Ardiomixer
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

    public WindowsAudioData getRunningAudioApllicationsData()
        {
            Ardiomixer.WindowsAudioData _Audiodata = new WindowsAudioData();
            Ardiomixer.RunningAudioApplicationsData _RunningAudioSessions = new RunningAudioApplicationsData();
            List<Process> _audioProcesses = Ardiomixer.WindowsAudioManager.GetAudioProcesses();
            try
            {
                foreach (Process _process in _audioProcesses)
                {
                    if (_process.Id != 0)
                    {
                        MessageBox.Show(_process.Id.ToString());
                        _RunningAudioSessions.ProcessID = _process.Id;
                        _RunningAudioSessions.ApplicationVolume = Ardiomixer.WindowsAudioManager.GetApplicationVolume(_process.Id);
                        _RunningAudioSessions.isApplicationMuted = Ardiomixer.WindowsAudioManager.GetApplicationMute(_process.Id);
                        _Audiodata.RunningApplications.Add(_RunningAudioSessions);
                    }
                    
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Fehler beim Auslesen der Audiosessions! - " + ex.Message);
            }

            return _Audiodata;
            
        }
    }
}
