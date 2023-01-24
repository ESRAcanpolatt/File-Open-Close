
#include <stdio.h>
#include <stdlib.h>
void fgetAnswers(){ 
	FILE *y; 
	FILE *yanlis;
	int Numara,soru_sayisi,i,ynlsr[40]; 
	char cvp_anht[40],cvp[40];  
	y=fopen("examdat.txt","r"); // r= dosyanýn okunmasýný gerçekleþtirir.
	yanlis=fopen("report.txt","w"); // w=dosyaya yazma iþlemini gerçekleþtirir.
	if(y==NULL){ //NULL henüz deðeri atanmamýþ olan þeyleri ifade eder.
		printf("Dosya okunamadi lutfen ayni klasörde olmasina dikkat et..."); //printf ekrana yazdýrma iþlemini gerçekleþtirir.
	}
	else{
		fscanf(y,"%d %s",&soru_sayisi,&cvp_anht); // %d=integer %s=string
		fprintf(yanlis,"Exam Report\n");
		fprintf(yanlis,"Soru");
		for(i=0;i<soru_sayisi;i++){  // for döngüsü =i deðerini 0 ata i soru sayýsýndan küçük olana kadar i yi birer birer arttýr.
			fprintf(yanlis,"%d",i+1); // Soru sayilarini yazan döngü.
		}
		fprintf(yanlis,"\nAnswer");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%c",cvp_anht[i]); // Cevap anahtarlarini yazan döngü.
		}
		fprintf(yanlis,"\nPuan(%c)\n");
		while(fscanf(y,"%d %s",&Numara,&cvp)!=EOF){ //EOF dosyanýn bittiðinin haberini bize vermektedir.
		    double Puan=0; //Puaný double þeklinde atadým.
			for(i=0;i<soru_sayisi;i++){
				if(cvp_anht[i]==cvp[i])
					Puan++; 
				else
					ynlsr[i]+=1; // kaçýrýlan sorular
			}
			int not=(double)100/soru_sayisi * Puan; //Bu iþlem yüzdesel puaný hesaplar.
			fprintf(yanlis,"%1d\n",Numara,not); // Dosyaya öðrencinin notunu yazdýrýr.
		}
		fprintf(yanlis,"\n");
		fprintf(yanlis,"Soru");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%d",i+1); // soru numarasý
		}
		fprintf(yanlis,"\n");
		fprintf(yanlis,"ynlsr ");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%d",ynlsr[i]); //yanlýs yapilan soru sayýsýný verir.
		}
		printf("Report.txt adli dosya olusturuldu");}
	fclose(y);// FILE*y dosyasýný kapattý
	fclose(yanlis);// FILE*yanlis dosyasýný kapattý 
	}
int main(){
	int n;
	printf("Lutfen baslamak icin bir rakam giriniz: "); 
	scanf("%d",&n);	
	fgetAnswers(); //Bizden istenilen fonksiyonu kapama.
	return 0;
}
