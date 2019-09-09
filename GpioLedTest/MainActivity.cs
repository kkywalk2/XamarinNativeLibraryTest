using Android.App;
using Android.OS;
using Android.Support.V7.App;
using Android.Runtime;
using Android.Widget;
using System.Runtime.InteropServices;

namespace GpioLedTest
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        [DllImport("libGpioLed.so", EntryPoint = "GpioLed")]
        public extern static int GpioLed(int input);

        Button button;
        bool on;
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.activity_main);

            button = FindViewById<Button>(Resource.Id.button);
            on = false;

            button.Click += delegate {
                if (on)
                {
                    GpioLed(0);
                    on = false;
                }
                else
                {
                    GpioLed(1);
                    on = true;
                }
            };
        }
    }
}