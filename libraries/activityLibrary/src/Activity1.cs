using Properties;
using System.Collections.Generic;
using System.Activities;
using System.Activities.Statements;
using System.Dynamic;
using System.Threading;

namespace ActivityLibrary
{
    public sealed class Activity1 : NativeActivity
    {
        public Activity Body { get; set; }

        public string Name { get; set; }

        public static System.Drawing.Bitmap Icon => new System.Drawing.Bitmap(Resources.Activity);

        protected override void Execute(NativeActivityContext context)
        {
            
            dynamic extensionObj = context.GetExtension<ExpandoObject>();
            extensionObj.label1text = "This is label 1 text";

            // Test for existence of AddList delegate before invoking it
            if (((IDictionary<string, object>)extensionObj).ContainsKey("AddList"))
            {
                extensionObj.AddList?.Invoke("this is a list item1");
            }
            Thread.Sleep(2000);
        }
    }
}