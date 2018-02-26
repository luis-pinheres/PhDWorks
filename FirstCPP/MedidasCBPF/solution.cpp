//Use  argc, argv[] to read a file.
//Author:Luis Pinheres.
//Date: 25 February 2018.


#include <fstream> //for file acess
#include <iostream>
#include <string>
#include <vector>
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"


 using namespace std;


  int main(int argc, char* argv[])
  {
   const int samples = 100;
   
   if (argc >1){
   cout<<"argv[1]="<<argv[1]<<endl;   
   } else{
   cout<<" No file name entered. Exiting..."<<endl;
   return -1;
   }
 
    // open file to read
    ifstream inFile(argv[1]);
    // inFile.open("raw_00000001_0001_1495054629.dat");
    //  if(!inFile.good())
    //  cout << " File not open! " << endl;
     
    if(inFile.is_open() && inFile.good()){
    cout<<"File is now open!\nContains:\n";
    string aLine= "";
     while(getline(inFile,aLine)){
    //  cout<<aLine<<'\n';
     }
    }  
    
    else {
         cout << "Failed to open file.."<<endl;
         }
    


   // Columnas        
   int  meas[samples];
   int col2[samples];
   int col3[samples];
   int m[samples];
   int dump; // lixo!
   // k lines(6477000)


   // skip first 11 lines
   string Line;
   int n=11;
   for( int i =0; i<n; ++i){
   getline(inFile,Line);
   cout << Line << endl;
   }

   // Plot 100 datas   
                                  
    for( int i = 0; i < samples ; ++i){
    inFile >> dump>> dump >> dump >> meas[i] //
     >>  col2[i] >> col3[i] >> dump >> dump >> dump >> dump>> dump ;
     m[i]=25*i;
                                                                                                                           
    cout <<" * "<<" *  "<<" * "<< meas[i] <<endl;
    // cout<<"--"<<col2[i]<<"--"<<col3[i]<<"******"<< endl;
                                                                                                
    }                                                                                                                                                    TCanvas*c1= new TCanvas("c1","A",200,10,700,500);                                                                                                     TGraph g(samples,m,meas); 
   gStyle->SetCanvasColor(0);
   gStyle->SetFrameBorderMode(0);
   gStyle->SetStatBorderSize(1);
   gStyle->SetFrameFillColor(0);
   gStyle->SetTitleFillColor(0);                   
                    
   g.SetLineColor(3);
   g.SetLineWidth(2);
   g.SetTitle("Channel-Plate-Event");
   g.GetXaxis()->SetTitle("t [ns]");
   g.GetYaxis()->SetTitle("adc count");                                                                                                                  g.Draw();                                                                                                                                             c1->Print("CPE1.pdf","pdf");                                                                                                                                                                                                                                                                                                                                                                                                                               
      return 0;
  }  

  
   
  //  if (argc<3){
  //  cerr<<"Usage: "<<argv[0]<<" "<<"SOURCE DESTINATION"<<endl;
 // return 1;
 // }
 // for(int i; i<argc; ++i){
 //  cout<<"argv["<<i<<"]="<<argv[i]<<endl;
 // }


  //return 0;
  




