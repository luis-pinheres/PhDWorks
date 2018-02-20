/**
 * @file MyFirstHistogram.cc
 */
// aqui voce comenta o que faz

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
  inFile.open("raw_00000001_0001_1495054629.dat");
  if(!inFile.good()) cout << " File not open! " << endl;

  // skip first n lines
  string aLine;
  int n=419;
  for( int i =0; i<n; ++i){
    getline(inFile,aLine);
//   cout << aLine << endl;
  }

// For the first channel of the first plate of first event , we must skip the n=11 lines
// For the first channel of the second plate of first event , we must skip the n=113 lines
// For the first channel of the second plate of second event, we must skip  the n=419 lines
// For the first channel of the second plate of second event , we must skip the n=725 lines

//cout<<"______________________________________"<<endl;
  

// Let's plot first channel of first event (for any plate and any event)
  int meas[samples];
  int x[samples];
  int dump; // lixo!
 for( int i = 0; i < samples ; ++i){
    inFile >> dump >> dump >> dump >> meas[i] //
           >> dump >> dump >> dump >> dump >> dump >> dump >> dump;   
    x[i]=25*i;
//   cout << meas[i] << endl;
  }


     TCanvas *c1 = new TCanvas("c1","A",200,10,700,500);

     TGraph g(samples,x,meas);
     g.SetLineColor(5);
     g.SetLineWidth(2);
     g.SetTitle("First Channel-Second  Plate - Second Event");
     g.GetXaxis()->SetTitle("t [ns]");     
     g.GetYaxis()->SetTitle("adc count");     
     g.Draw();
     // CPE(CHANNEL, PLATE, EVENT)
     c1->Print("CPE(1,2,2).pdf","pdf");
     return 0;
}
#endif
