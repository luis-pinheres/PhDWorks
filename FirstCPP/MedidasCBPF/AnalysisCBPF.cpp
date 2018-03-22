/*We use  argc, argv[] to read the CBPF.dat file and  Draw a Histogram.
Author:Luis Pinheres.
Date: 22 March 2018.
*/

#include <fstream> 
#include <iostream>
#include <string>
#include <vector>
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TArrow.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"

#include "Signal.h"

 using namespace std;


  int main(int argc, char* argv[])
  {
   const int samples = 100;

   int boardNum;
   int channelNum;

   // set parameters from input   
   if (argc == 4){
     cout<<"argv[1]="<<argv[1]<<endl;   
     boardNum = atoi(argv[2]);
     channelNum = atoi(argv[3]);
     cout << " Board number   : " << boardNum << endl;
     cout << " Channel number : " << channelNum << endl; 
   }else{
     cout << " Usage:" << endl;
     cout << " ./solution PATH BOARD CHANNEL " << endl;
     cout << endl;
     cout << " PATH    : input data file with absolute path " <<  endl; 
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

  // Columns
   int channel[8];        
   int meas[samples];// measurement value
   int m[samples];// measurement index
   int dump; // lixo!

  // skip first 11 lines (header)
   string Line;
   int z=11;
   for( int i =0; i<z; ++i){
    getline(inFile,Line);
    //cout << Line << endl;
   }

  // create histogram
  TH1F testHisto("testHisto","testHisto", 1000, 10, 990 );
  TH2F testHisto2("testHisto2","testHisto2",500,-250,250,4000,-250,3750);
  gStyle->SetOptStat(kFALSE);//Define the statistical
  
  // now read channel / board
  int board = 0;
  int eventRead=0;
  while(eventRead<=15874){
 
    eventRead++;
    signal aSig;
    for(int k =0; k<4; k++){
      for( int i = 0; i < samples ; ++i){
        inFile >> dump>> dump >> dump ;
        for(int j = 0; j < 8; j++) inFile >> channel[j];
        meas[i]=channel[channelNum-1];
        m[i]=25*i; 
                                               
                                                                  
      }
      for(int l=0;l<11;l++) inFile >> dump;
      inFile >> dump >> board >> dump >> dump >> dump >> dump >> dump >> dump >> dump >> dump >>  dump;
     
      if(board==boardNum){
        aSig.setData(samples,meas);
     }  
    
    }

    // Fill histogram

      testHisto.Fill(aSig.charge());
      testHisto2.Fill(aSig.minimo(),aSig.area());
     
    }

  // now make plot, save and exit
  TCanvas*c1= new TCanvas("c1","c1",300,200,600,400); 
  gStyle->SetCanvasColor(1);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetStatBorderSize(1);
  gStyle->SetFrameFillColor(1);
  gStyle->SetTitleFillColor(1);

  // Drawing options                  
  testHisto.SetFillColor(3);
  testHisto.SetFillStyle(3004);
  testHisto.SetLineColor(4);
  testHisto.SetMarkerStyle(7);
  testHisto.SetLineWidth(1); 
  testHisto.SetTitle("Histogram Integral");
  testHisto.GetXaxis()->SetTitle("Area[A.U]");
  testHisto.GetYaxis()->SetTitle("# Event");
  testHisto.Draw();

  // Write a text in the plot
  TText *xlabel = new TText();
  xlabel-> SetNDC();
  xlabel -> SetTextFont(1);
  xlabel -> SetTextColor(1);
  xlabel -> SetTextSize(0.03);
  xlabel -> SetTextAlign(22);
  xlabel -> SetTextAngle(0);
  xlabel -> DrawText(0.2,0.02,"Author:PhD. Student Luis Pineres.");
  
  // Add a Legend
  TLegend leg(.9,.8,.7,.6);
  leg.SetHeader("Raw:1495054629.dat","C");
  leg.SetFillColor(0);
  leg.SetBorderSize(1);
  leg.AddEntry((TObject*)0, "Event Number:15874", "C");
  leg.AddEntry((TObject*)0, "Board Number:6", "C");
  leg.AddEntry((TObject*)0, "Channel Number:1", "C");
  leg.AddEntry(&testHisto,"Escala linear");
  leg.Draw("Same");
 
  // save Histogram
  c1->Print("Integral.pdf","pdf");
  
  return 0;
}  





