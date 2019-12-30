#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,max, max_v,min_v;
	int first_value, second_value, sum;
	
	int odwroc_liczbe(int liczba){
		int odwr = floor(log10(liczba)+1);
		int wynik=0;
			
			for(i=1; i<=odwr; i++){
			wynik += floor(pow(10,odwr-i))* (liczba%10);
			liczba /=10;
			}
		return wynik;
		}	
	
	printf("a = ");
	scanf("%d", &first_value);
	
	printf("b = ");
	scanf("%d", &second_value);
	
	sum = first_value + second_value;
	//odwrócenie liczb
	int rev_f = odwroc_liczbe(first_value);
	int rev_s = odwroc_liczbe(second_value);
	int rev_o = odwroc_liczbe(sum);
	
	//tablice liczb
	char jedynki[10];
	itoa(rev_f,jedynki,10);
	char dwojki[10];
	itoa(rev_s,dwojki,10);
	char suma[10];
	itoa(rev_o,suma,10);
	
	//długość
	int fv = floor(log10(first_value)+1);
	int sv = floor(log10(second_value)+1);
	int s = floor(log10(sum)+1);
	
	if(fv>=sv){
		max = fv;
		max_v = first_value;
		min_v = second_value;
		}else{
			max = sv;
			min_v = first_value;
			max_v = second_value;
		}
	
	//jedynki
	printf("\n");
	for (i=max;i>=0;i--){
		//zamiana char na int
		int m = jedynki[i] - '0';
		int n = dwojki[i] - '0';
		int o = suma[i] - '0';
		
			if( m+n >= 10 || o==0){
				printf("1");
			}else if(o!=0 &&  m+n < 10 ){
					printf(" ");
			}
	}
		
	printf("\n");
	printf("  %*d\n",max, max_v);
	printf("+ %*d\n",max, min_v);
	
	for(i=0;i<(max+2);i++){
        printf("-");
    }
    
    printf("\n");
    if(s>max){
    	printf(" %*d\n",s, sum);
	}else{
		printf("  %*d\n",max, sum);
	}   
	system("pause");  	
}
