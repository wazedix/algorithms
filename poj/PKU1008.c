# include<stdio.h>

const char haab[19][10] = { {"pop"},{"no"},{"zip"},{"zotz"},
							{"tzec"},{"xul"},{"yoxkin"},{"mol"},
							{"chen"},{"yax"},{"zac"},{"ceh"},
							{"mac"},{"kankin"},{"muan"},{"pax"},
							{"koyab"},{"cumhu"},{"uayet"} };
const char tzolkin[20][10] = { {"imix"},{"ik"},{"akbal"},{"kan"},
							   {"chicchan"},{"cimi"},{"manik"},{"lamat"},
							   {"muluk"},{"ok"},{"chuen"},{"eb"},
							   {"ben"},{"ix"},{"mem"},{"cib"},
							   {"caban"},{"eznab"},{"canac"},{"ahau"} };

int main()
{
	int n,i,j,s;
	int month0,day,year,day0,year0;
	char month[10];
	scanf("%d\n",&n);
	printf("%d\n",n);
	for (i=1;i<=n;i++)
		{
			scanf("%d. %s %d",&day,&month,&year);
			s=day+year*365;
			for (j=0;j<=18;j++)
				if ((haab[j][0]==month[0])&&
					(haab[j][1]==month[1])) 
				{
					s+=j*20;
					break;
				}
			day0=0; 
			month0=1;
			year0=0;	
			for (j=1;j<=s;j++)
			{
				day0=(day0+1)%20;
				month0=(month0+1)%13;
				if ((month0==1)&&(day0==0)) year0++;
				if (month0==0) month0=13;
			}
			printf("%d %s %d\n",month0,tzolkin[day0],year0);
		}
	return 0;
}
