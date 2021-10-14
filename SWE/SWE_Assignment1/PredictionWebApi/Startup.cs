using ImageClassification.DataModels;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.ML;
using PredictionWebApi.DataModels;
using SWE_Assignment1;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace PredictionWebApi
{
    public class Startup
    {
        public Startup(IConfiguration configuration)
        {
            Configuration = configuration;
        }

        public IConfiguration Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            services.AddPredictionEnginePool<MLModel1.ModelInput, ImagePrediction>()
                    .FromFile(GetAbsolutePath(Configuration["MLModel:MLModelFilePath"]));
            // Register the Swagger generator, defining 1 or more Swagger documents
            services.AddSwaggerGen();

            services.AddControllers();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            // Enable middleware to serve generated Swagger as a JSON endpoint.
            app.UseSwagger();

            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
            }

            // Enable middleware to serve swagger-ui (HTML, JS, CSS, etc.)
            app.UseSwaggerUI();

            app.UseRouting();
            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllers();
            });

            

            app.UseAuthorization();

            app.UseEndpoints(endpoints =>
            {
                endpoints.MapControllers();
            });
        }

        public static void WarmUpPredictionEnginePool(IServiceCollection services)
        {
            //#1 - Simply get a Prediction Engine
            var predictionEnginePool = services.BuildServiceProvider().GetRequiredService<PredictionEnginePool<MLModel1.ModelInput, ImagePrediction>>();
            var predictionEngine = predictionEnginePool.GetPredictionEngine();
            predictionEnginePool.ReturnPredictionEngine(predictionEngine);

            // #2 - Predict
            // Get a sample image
            //
            //Image img = Image.FromFile(@"TestImages/BlackRose.png");
            //byte[] imageData;
            //IFormFile imageFile;
            //using (MemoryStream ms = new MemoryStream())
            //{
            //    img.Save(ms, System.Drawing.Imaging.ImageFormat.Png);
            //    //To byte[] (#1)
            //    imageData = ms.ToArray();

            //    //To FormFile (#2)
            //    imageFile = new FormFile((Stream)ms, 0, ms.Length, "BlackRose", "BlackRose.png");
            //}

            //var imageInputData = new InMemoryImageData(image: imageData, label: null, imageFileName: null);

            //// Measure execution time.
            //var watch = System.Diagnostics.Stopwatch.StartNew();

            //var prediction = predictionEnginePool.Predict(imageInputData);

            //// Stop measuring time.
            //watch.Stop();
            //var elapsedMs = watch.ElapsedMilliseconds;
        }

        public static string GetAbsolutePath(string relativePath)
        {
            var _dataRoot = new FileInfo(typeof(Program).Assembly.Location);
            string assemblyFolderPath = _dataRoot.Directory.FullName;

            string fullPath = Path.Combine(assemblyFolderPath, relativePath);
            return fullPath;
        }

    }
}
