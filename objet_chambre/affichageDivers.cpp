#include "main.h"




String editForm(int data, int limit, char c)
{
  if(data < -10)
    return "-!";
  else if(data < 0)
    return "-" + String(abs(data));
  else if(data < 10)
    return c + String(data);
  else if(data < limit)
    return String(data);
  else
    return "!!";
}



String dateForm(int jour, int mois, int annee)
{
  int c = (14 - mois) / 12;
  int a = annee - c;
  int m = mois + 12 * c - 2;
  int j = (jour + a + a/4 - a/100 + a/400 + (31*m)/12) % 7;

  return jourL[j] + " " + jour + " " + moisL[mois-1];
}



int nbJourDansMois(int month, int year)
{
  if (month == 4 || month == 6 || month == 9 || month == 11)  
    return 30;  
  else if (month == 2)  
  {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  
    if (isLeapYear)  
      return 29;  
    else  
      return 28;  
  }  
  else  
    return 31; 
}



