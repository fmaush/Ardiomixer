using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ardiomixer
{
    public class WindowsAudioData
    {
        public float MasterVolume { get; set; }

        public bool isMasterVolumeMuted { get; set; }

        public List<RunningAudioApplicationsData> RunningApplications;
    }


    public class RunningAudioApplicationsData
    {
        public int ProcessID { get; set; }

        public float ApplicationVolume { get; set; }

        public bool isApplicationMuted { get; set; }

    }
}
