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

   int evtNum;
   int boardNum;
   int channelNum;

   // set parameters from input   
   if (argc == 5){
     cout<<"argv[1]="<<argv[1]<<endl;   
     evtNum = atoi(argv[2]);
     boardNum = atoi(argv[3]);
     channelNum = atoi(argv[4]);
     cout << " Event number   : " << evtNum <<  endl;
     cout << " Board number   : " << boardNum << endl;
     cout << " Channel number : " << channelNum << endl; 
   }else{
     cout << " Usage:" << endl;
     cout << " ./solution PATH EVENT BOARD CHANNEL " << endl;
     cout << endl;
     cout << " PATH    : input data file with absolute path " <<  endl; 
     cout << " EVENT   : event number to select " << endl;
     cout << " BOARD   : board number to select " << endl;
     cout << " CHANNEL : channel number to select " << endl; 
     return -1;
   }

  // open file to read
  ifstream inFile(argv[1]);
  if(inFile.is_open() && inFile.good())
    cout<<"File is now open!\nContains:\n";
  else
    cout << "Failed to open file.."<<endl;

  // Columnas
  int channel[8];        
  int meas[samples];// measurement value
  int m[samples];// measurement index
  int dump; // lixo!

  // skip first 11 lines (header)
  string Line;
  int n=11;
  for( int i =0; i<n; ++i){
    getline(inFile,Line);
    cout << Line << endl;
  }

  //  skip events to select evtNum 
  for( int i = 0; i < 4*102*(evtNum-1); i++){
    getline(inFile,Line);
  }

  // now read channel / board
  int board = 0;
  while(board != boardNum){
    for( int i = 0; i < samples ; ++i){
     
      inFile >> dump>> dump >> dump ;
      for(int j = 0; j < 8; j++) inFile >> channel[j];
      meas[i]=channel[channelNum-1];
      m[i]=25*i;                                                                                    
      cout <<" * "<<" *  "<<" * "<< meas[i] <<endl;                                                                                  
    }
    for(int i=0;i<11;i++) inFile >> dump;
    inFile >> dump >> board >> dump >> dump >> dump >> dump >> dump >> dump >> dump >> dump >>  dump;
    cout << " board " << board << endl;
  } 

  // now make plot, save and exit
  TCanvas*c1= new TCanvas("c1","A",200,10,700,500);
  TGraph g(samples,m,meas); 
  gStyle->SetCanvasColor(1);
  gStyle->SetFrameBorderMode(1);
  gStyle->SetStatBorderSize(1);
  gStyle->SetFrameFillColor(1);
  gStyle->SetTitleFillColor(1);                   
                   
  g.SetLineColor(3);
  g.SetLineWidth(2);
  g.SetTitle("Channel-Plate-Event");
  g.GetXaxis()->SetTitle("t [ns]");
  g.GetYaxis()->SetTitle("adc count");                                                                                                                  g.Draw();                                                                                                                                             c1->Print("CPE1.pdf","pdf");

  return 0;
}  





