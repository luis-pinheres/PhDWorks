
/*Plot the Signal of CBPF Datas
This program reads an archive.dat using commands lines, and  it draws the signal.
Author:Luis Pinheres.
Date: 22 March 2018.
*/


  // We define the libraries
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
#include "TF1.h"
#include "TPaveText.h"
#include "TText.h"
#include "TPaveStats.h"
//#include "Signal.h"

 using namespace std;


  int main(int argc, char* argv[])
  {
   const int samples = 100;

   int evtNum;
   int boardNum;
   int channelNum;

   // Set parameters from input   
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

  // Open file to read
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

  // Skip first 11 lines (header)
   string Line;
   int z=11;
   for( int i =0; i<z; ++i){
    getline(inFile,Line);
    cout << Line << endl;
   }

  // Skip events to select evtNum 
  for( int i = 0; i < 4*102*(evtNum-1); i++){
    getline(inFile,Line);
  }

  // Now read channel / board
  int board = 0;
  while(board != boardNum){
    for( int i = 0; i < samples ; ++i){
     
      inFile >> dump>> dump >> dump ;
      for(int j = 0; j < 8; j++) inFile >> channel[j];
      meas[i]=channel[channelNum-1];
      m[i]=25*i;                                                                                    
                                                                                    
    }
    for(int i=0;i<11;i++) inFile >> dump;
    inFile >> dump >> board >> dump >> dump >> dump >> dump >> dump >> dump >> dump >> dump >>  dump;
  
  } 

  // Now make plot
  TCanvas*c1= new TCanvas("c1","c1",400,500,900,700);
  
  // Define the pulse
  TGraph g(samples,m,meas); 
  gStyle->SetCanvasColor(1);
  gStyle->SetFrameBorderMode(5);
  gStyle->SetStatBorderSize(4);
  gStyle->SetFrameFillColor(1);
  g.SetMarkerStyle(7);                 
  g.SetFillColor(8);
  g.SetLineColor(8);
  g.SetLineWidth(6);
  g.SetTitle("Pulso");
  g.GetXaxis()->SetTitle("t [ns]");
  g.GetYaxis()->SetTitle("adc count");
  g.Draw(); 
  
  // Make the pedestal
  TF1 efunc("efunc","-108.7",0.,2600.);
  efunc.SetLineColor(kBlue);
  efunc.SetLineWidth(3);
  efunc.Draw("same");
   
  // Build and Draw a legend
  TLegend leg(.9,.8,.7,.6);
  leg.SetHeader("Raw:1495054629.dat","C");
  leg.SetFillColor(0);
  leg.SetBorderSize(1);
  leg.AddEntry((TObject*)0, "Event Number:1", "C");
  leg.AddEntry((TObject*)0, "Board Number:6", "C");
  leg.AddEntry((TObject*)0, "Channel Number:1", "C");
  leg.AddEntry(&g,"Sinal");
  leg.AddEntry(&efunc,"Pedestal");
  leg.Draw("Same");
  
  
  // Build and Draw an arrow
  TArrow arrow(800,-100,1000,-95,0.02,"|>");
  arrow.SetLineWidth(1);
  arrow.Draw();

  TArrow arrow2(700,-110,500,-109,0.01,"|>");
  arrow2.SetLineWidth(1);
  arrow2.Draw();


  // Draw the height of the pulse
  TLine *line = new TLine(400,-75,400,-109);
  line->SetLineColor(kRed);
  line->SetLineWidth(1);
  line->Draw();

  TLine *liner = new TLine(300,-75,500,-75);
  liner->SetLineColor(kRed);
  liner->SetLineWidth(1);
  liner->Draw("same");

  TLine *linera = new TLine(300,-109,500,-109);
  linera->SetLineColor(kRed);
  linera->SetLineWidth(1);
  linera->Draw("same");

  // Draw the area
  TLine *a = new TLine(550,-109.4,550,-107.4);
  a->SetLineColor(6);
  a->SetLineWidth(1);
  a->SetLineStyle(5);
  a->Draw("same");

  TLine *b = new TLine(600,-109.4,600,-90);
  b->SetLineColor(6);
  b->SetLineWidth(2);
  b->SetLineStyle(5);
  b->Draw("same");

  TLine *c = new TLine(650,-109.4,650,-79);
  c->SetLineColor(6);
  c->SetLineWidth(2);
  c->SetLineStyle(5);
  c->Draw("same");


  TLine *d = new TLine(700,-109.4,700,-78);
  d->SetLineColor(6);
  d->SetLineWidth(2);
  d->SetLineStyle(5);
  d->Draw("same");

  TLine *e = new TLine(750,-109.4,750,-85);
  e->SetLineColor(6);
  e->SetLineWidth(1);
  e->SetLineStyle(5);
  e->Draw("same");

  TLine *f = new TLine(800,-109.4,800,-90.5);
  f->SetLineColor(6);
  f->SetLineWidth(2);
  f->SetLineStyle(5);
  f->Draw("same");

  TLine *h = new TLine(850,-109.4,850,-97);
  h->SetLineColor(6);
  h->SetLineWidth(2);
  h->SetLineStyle(5);
  h->Draw("same");


  TLine *f1 = new TLine(900,-109.4,900,-100);
  f1->SetLineColor(6);
  f1->SetLineWidth(2);
  f1->SetLineStyle(5);
  f1->Draw("same");

  TLine *f2 = new TLine(950,-109.4,950,-104);
  f2->SetLineColor(6);
  f2->SetLineWidth(2);
  f2->SetLineStyle(5);
  f2->Draw("same");

  TLine *f3 = new TLine(1000,-109.4,1000,-105.4);
  f3->SetLineColor(6);
  f3->SetLineWidth(2);
  f3->SetLineStyle(5);
  f3->Draw("same");


  TLine *f4 = new TLine(1050,-109.4,1050,-106.2);
  f4->SetLineColor(6);
  f4->SetLineWidth(2);
  f4->SetLineStyle(5);
  f4->Draw("same");


  TLine *f5 = new TLine(1100,-109.4,1100,-108);
  f5->SetLineColor(6);
  f5->SetLineWidth(2);
  f5->SetLineStyle(5);
  f5->Draw("same");

  TLine *f6 = new TLine(1150,-109.4,1150,-108);
  f6->SetLineColor(6);
  f6->SetLineWidth(2);
  f6->SetLineStyle(5);
  f6->Draw("same");

  // Write a text
  TText *xlabel = new TText();
  xlabel-> SetNDC();
  xlabel -> SetTextFont(1);
  xlabel -> SetTextColor(1);
  xlabel -> SetTextSize(0.03);
  xlabel -> SetTextAlign(22);
  xlabel -> SetTextAngle(0);
  xlabel -> DrawText(0.3,  0.13, "Start time");
  xlabel -> DrawText(0.43, 0.5, "Pulse Integral");
  xlabel -> DrawText(0.83, 0.15, "Pedestal");
  xlabel -> DrawText(0.18 , 0.6,"Pulse");
  xlabel -> DrawText(0.18 , 0.58," Height");
  xlabel -> DrawText(0.25,0.02,"Author:PhD. Student Luis Pineres (22-03-2018).");
  

  // Save the Canvas 
  c1->Print("Pulso1.pdf","pdf");
  
                                                                            
  return 0;
}  




