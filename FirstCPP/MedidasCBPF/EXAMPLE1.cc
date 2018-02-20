
 #include <iostream>
 #include <fstream>
 #include <string>
 #include "TCanvas.h"
 #include "TGraph.h"

  using namespace std;
 
  #ifndef __CINT__
 
  int main(void)
  {

   const int samples = 100;

     // open file to read
      ifstream inFile;
      inFile.open("raw_00000001_0001_1495054629.dat");
      if(!inFile.good()) cout << " File not open! " << endl;

      // skip first 114 lines
       string aLine;
       for( int i =0; i<11; ++i){
       getline(inFile,aLine);
        //cout << aLine << endl;
                                }

       // Let's plot first channel of first event
          int meas[samples];
          int p[samples];
          int dump; // lixo!
          for( int i = 0; i < samples ; ++i){
          inFile >> dump >> dump >> dump >> dump>> meas[i] //
          >> dump >> dump >> dump  >> dump >> dump >> dump;   
          p[i]=i;
        //  cout << meas[i] << " ";
                                         }
        //  cout << endl;

           TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
           TGraph g(samples,p,meas);
           g.SetLineColor(4);
           g.SetTitle("name");
          // g.GetXaxis()->SetTitle("X");
          // g.GetYaxis()->SetTitle("Y");
           g.Draw();
           c1->Print("GRAFICA.pdf","pdf");
                                                                                      
     
  return 0;
   }
                                                                                  #endif
