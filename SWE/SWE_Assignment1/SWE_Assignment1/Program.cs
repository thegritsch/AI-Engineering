using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Linq.Expressions;
using System.Linq;

namespace SWE_Assignment1
{
    class Program
    {
        /// <summary>
        /// This program loads all the .png files in the executing directory and tries to predict a number from 0-9 on the image
        /// Output is printed to the console, together with the scores
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {

            List<MLModel1.ModelInput> inputs = new List<MLModel1.ModelInput>();
            //Load model and predict output
            
            DirectoryInfo info = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);

            foreach (FileInfo file in info.EnumerateFiles("*.png"))
            {
                
                var sampleData = new MLModel1.ModelInput()
                {
                    ImageSource = file.FullName,
                };
                inputs.Add(sampleData);
            }

            foreach(var input in inputs)
            {
                var result = MLModel1.Predict(input);
                Console.WriteLine($"+++++ Prediction Result: {result.Prediction}; Confidence: ");
                int count = 0;
                foreach(var score in result.Score)
                {
                    Console.WriteLine($"Score for {count}: {score}");
                    count++;
                }
            }

        }
    }
}
