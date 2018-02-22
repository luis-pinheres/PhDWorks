
 #include <iostream>
 #include <fstream>
 #include <string>
 #include "TStyle.h"
 #include "TCanvas.h"
 #include "TGraph.h"
 #include "TAxis.h"

 using namespace std;

  #ifndef __CINT__
 
  int main()
  {

   const int samples = 100;

     // open file to read
       ifstream inFile;
       inFile.open("/home/luis/Documentos/UEL/PIETROCHIMENTI/MedidasCBPF/programas/raw_00000001_0001_1495054629.dat");
           if(!inFile.good()) cout << " File not open! " << endl;

//indica la columna a leer        
  int  meas[samples];
  int col2[samples];
  int col3[samples];
  int m[samples];
  int dump; // lixo!
 // k lines(6477000)
 

          // skip first 11 lines
            string aLine;
            int n=11;
            for( int i =0; i<n; ++i){
            getline(inFile,aLine);
           // cout << aLine << endl;
                                    }

           // Plot 100 datas   
                                
             for( int i = 0; i < samples ; ++i)
             {
               inFile >> dump>> dump >> dump >> meas[i] //
               >>  col2[i] >> col3[i] >> dump >> dump >> dump >> dump>> dump ;
               m[i]=25*i;
                 
                // cout <<" * "<<" *  "<<" * "<< meas[i] <<endl;
                // cout<<"--"<<col2[i]<<"--"<<col3[i]<<"******"<< endl;
                 }                          
                   TCanvas*c1= new TCanvas("c1","A",200,10,700,500);
                    gStyle->SetCanvasColor(0);
                    gStyle->SetFrameBorderMode(0);
                    gStyle->SetStatBorderSize(1);
                    gStyle->SetFrameFillColor(0);
                    gStyle->SetTitleFillColor(0);                   
                    TGraph g(samples,m,meas);
                    g.SetLineColor(3);
                    g.SetLineWidth(2);
                    g.SetTitle("1er Channel-first  Plate - First Event");
                    g.GetXaxis()->SetTitle("t [ns]");
                    g.GetYaxis()->SetTitle("adc count");
                    g.Draw();
                   // CPE(CHANNEL, PLATE, EVENT)
                    c1->Print("CPE1.pdf","pdf");
                 
              
              //skip 2 lines
              
                for(int i=0; i<3; ++i){
                 getline(inFile,aLine);
               //  cout<<aLine<<endl; 
                                      }                      
             //cout<<"_________________"<<endl;
             
               // plot 100 datas
             for(int j = 0; j < samples ; ++j)
             {
               inFile >> dump>> dump >> dump >> meas[j] //
               >>  col2[j] >> col3[j] >> dump >> dump >> dump >> dump>> dump ;
               m[j]=25*j;

               // cout <<" -- "<<" *  "<<" -- "<< meas[j] <<endl;
               // cout<<"--"<<col2[j]<<"--"<<col3[j]<<"******"<< endl;
                                              }
               TCanvas*c2= new TCanvas("c2","A",200,10,700,500);
                 gStyle->SetCanvasColor(0);
                 gStyle->SetFrameBorderMode(0);
                 gStyle->SetStatBorderSize(1);
                 gStyle->SetFrameFillColor(0);
                 gStyle->SetTitleFillColor(0);
                 gStyle->SetStatBorderSize(1);

                TGraph g1(samples, m,meas);
                 g1.SetLineColor(4);
                 g1.SetTitle("1er Channel-2 Plate - 1er Event"); 
                 g1.GetXaxis()->SetTitle("t [ns]");   
                 g1.GetYaxis()->SetTitle("adc count");
                 g1.SetLineWidth(2);
                 g1.Draw(); 
                 c2->Print("CPE2.pdf","pdf");                             
               

                // skip 2 lines
                 for(int i=0; i<3; ++i){
                 getline(inFile,aLine);
                // cout<<aLine<<endl;
                    }                      
                // cout<<"uuuuuu_________________"<<endl;
              

               // plot 100 datas
            for(int j=0;j<samples;++j)
              {
               inFile >> dump>> dump >> dump >> meas[j] //
               >>  col2[j] >> col3[j] >> dump >> dump >> dump >> dump>> dump ;
               m[j]=25*j;
              // cout <<" -- "<<" *  "<<" -- "<< meas[j] <<endl;
                         } 
               
              TCanvas*c3= new TCanvas("c3","A",200,10,700,500);
                 gStyle->SetCanvasColor(0);
                 gStyle->SetFrameBorderMode(0);
                 gStyle->SetStatBorderSize(1);                                                                                                                         gStyle->SetFrameFillColor(0);                                                                                                                                                                                                                                                                            TGraph g2(samples,m,meas); 
                 g2.SetTitle("1er Channel-3  Plate - 1er Event");
                 g2.GetXaxis()->SetTitle("t [ns]");
                 g2.GetYaxis()->SetTitle("adc count");
                 g2.SetLineColor(5);
                 g2.SetLineWidth(2);
                 g2.Draw();
                 c3->Print("CPE3.pdf","pdf");    
         


                 // skip 2 lines
                  for(int i=0; i<3; ++i){
                 getline(inFile,aLine);
                // cout<<aLine<<endl; 
                                        }                      
               
                // plot 100 datas 
                 for(int j=0; j<samples; ++j)
                   {
                    inFile >> dump>> dump >> dump >> meas[j] //
                    >>  col2[j] >> col3[j] >> dump >> dump >> dump >> dump>> dump ;
                    m[j]=25*j;
                   // cout <<" -- "<<" --  "<<" -- "<< meas[j] <<endl;
                     }
                                                                                                                                                               TCanvas*c4= new TCanvas("c4","A",200,10,700,500);          
            TGraph g3(samples,m,meas);
            gStyle->SetCanvasColor(0);
            gStyle->SetFrameBorderMode(0);
            gStyle->SetStatBorderSize(1);
            gStyle->SetFrameFillColor(1);
            g3.SetTitle("1er Channel-4 Plate -1er Event");
            g3.GetXaxis()->SetTitle("t [ns]");
            g3.GetYaxis()->SetTitle("adc count");
            g3.SetLineColor(2);
            g3.SetLineWidth(2);
            g3.Draw();
            c4->Print("CPE4.pdf","pdf");
         return 0; 
       }
          #endif
                                                          
