//Codigo donde graficamos un Histograma y una funcion al mismo tiempo.
//Resuelto por: Luis F. Pineres Rico
//Fecha:5-03-2018



//Definimos las librerias
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
 



  using namespace std;


  int main()
  {
   
   //Definimos nuestro espacio 
   TCanvas *c = new TCanvas(); 
   gStyle->SetOptStat(111111);
   
   // Creamos nuestro primer Histogramas
   TH1F* h1 = new TH1F("h1","Data Analysis",400,-10,10);
   
   // Definimos nuestra distribución de tipo Gaussiana
   h1->FillRandom("gaus",300000);
   
   // Detalles de estetica para el grafico
   h1->SetFillColor(7);
   h1->SetFillStyle(3003);
   h1->SetMarkerColor(4);
   h1->SetMarkerStyle(25);
   h1->SetLineStyle(9);
   h1->GetXaxis()->SetTitle("Gaussian");
   h1->SetLineColor(kYellow);
   h1->Fit("gaus");
   h1->Draw();

   // Creamos una función y los detalles del grafico
   TF1 *f1=new TF1("f1","1000*TMath::Abs((sin(x)/x))",-10,10);
   f1->SetLineColor(kBlue);
   f1->SetLineWidth(1);
   f1->Draw("same");

   // Leyenda del grafico
   TLegend* leg = new TLegend(0.12,0.7,0.3,0.89);
   leg->SetHeader("The Legend Title");
   leg->AddEntry(h1,"Histogram Gaussian Distribution","f");
   leg->AddEntry("f1","f(x)=abs(sinx/x)","l");
   leg->SetFillColor(0);
   leg->Draw();

   // guardamos nuestro grafico como  .pdf
   c->Print("GRAFICA.pdf","pdf");
   
   return 0;

}
