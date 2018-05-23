void compute(double R0, double R1, double R2, double R)
{
  double n = 2.75;
  double a = 7.6;

  double DeltaLambda = 100*(TMath::Power((TMath::Log(R0-R) - TMath::Log(R2-R))/a,1/n) - TMath::Power((TMath::Log(R0-R) - TMath::Log(R1-R))/a,1/n));

  double dDeltaLambda_dR1 = 100*1/n*1/TMath::Power(a,1/n)*1/(R1-R)*TMath::Power(TMath::Log(R0-R) - TMath::Log(R1-R),1/n-1); 
  double dDeltaLambda_dR2 = -100*1/n*1/TMath::Power(a,1/n)*1/(R2-R)*TMath::Power(TMath::Log(R0-R) - TMath::Log(R2-R),1/n-1); 
  double dDeltaLambda_dR0 = 100*1/n*1/TMath::Power(a,1/n)*1/(R0-R)*(TMath::Power(TMath::Log(R0-R) - TMath::Log(R2-R),1/n-1) - TMath::Power(TMath::Log(R0-R) - TMath::Log(R1-R),1/n-1)); 
  double dDeltaLambda_dR = 100*1/n*1/TMath::Power(a,1/n)*  (  (-1/(R0-R)+1/(R2-R))*(TMath::Power(TMath::Log(R0-R) - TMath::Log(R2-R),1/n-1)) - (-1/(R0-R)+1/(R1-R))*(TMath::Power(TMath::Log(R0-R) - TMath::Log(R1-R),1/n-1))); 

  
  double dR1 = TMath::Sqrt(R1/600);
  double dR2 = TMath::Sqrt(R2/600);
  double dR0 = TMath::Sqrt(R0/60);
  double dR = TMath::Sqrt(R/1000);
  

  /*
  double dR1 = TMath::Sqrt(R1/200);
  double dR2 = TMath::Sqrt(R2/200);
  double dR0 = TMath::Sqrt(R0/60);
  double dR = TMath::Sqrt(R/200);
  */

  double dDeltaLambda = TMath::Sqrt(TMath::Power(dDeltaLambda_dR1,2)*TMath::Power(dR1,2) + TMath::Power(dDeltaLambda_dR2,2)*TMath::Power(dR2,2) + TMath::Power(dDeltaLambda_dR0,2)*TMath::Power(dR0,2) + TMath::Power(dDeltaLambda_dR,2)*TMath::Power(dR,2));

  double dDeltaLambda_woSquares = fabs(dDeltaLambda_dR1*dR1) + fabs(dDeltaLambda_dR2*dR2) + fabs(dDeltaLambda_dR0*dR0) + fabs(dDeltaLambda_dR*dR);

  std::cout<<std::endl<<"---- Results -----"<<std::endl<<std::endl;
  std::cout<<" T1 = "<<(R1-R)/(R0-R)<<"   T2 = "<<(R2-R)/(R0-R)<<std::endl<<std::endl;
  std::cout<<" dDeltaLambda_dR1 = "<<dDeltaLambda_dR1<<std::endl;
  std::cout<<" dDeltaLambda_dR2 = "<<dDeltaLambda_dR2<<std::endl;
  std::cout<<" dDeltaLambda_dR0 = "<<dDeltaLambda_dR0<<std::endl;
  std::cout<<" dDeltaLambda_dR = "<<dDeltaLambda_dR<<std::endl;

  std::cout<<" dR1 = "<<dR1<<std::endl;
  std::cout<<" dR2 = "<<dR2<<std::endl;
  std::cout<<" dR0 = "<<dR0<<std::endl;
  std::cout<<" dR = "<<dR<<std::endl;

  std::cout<<std::endl<<" DeltaLambda = "<<DeltaLambda<<" +- "<<dDeltaLambda<<"     (dDeltaLambda_woSquares = "<<dDeltaLambda_woSquares<<")"<<std::endl<<std::endl;
}
