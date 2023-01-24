
#include <stdio.h>
#include <stdlib.h>
void fgetAnswers(){ 
	FILE *y; 
	FILE *yanlis;
	int Numara,soru_sayisi,i,ynlsr[40]; 
	char cvp_anht[40],cvp[40];  
	y=fopen("examdat.txt","r"); // r= dosyan�n okunmas�n� ger�ekle�tirir.
	yanlis=fopen("report.txt","w"); // w=dosyaya yazma i�lemini ger�ekle�tirir.
	if(y==NULL){ //NULL hen�z de�eri atanmam�� olan �eyleri ifade eder.
		printf("Dosya okunamadi lutfen ayni klas�rde olmasina dikkat et..."); //printf ekrana yazd�rma i�lemini ger�ekle�tirir.
	}
	else{
		fscanf(y,"%d %s",&soru_sayisi,&cvp_anht); // %d=integer %s=string
		fprintf(yanlis,"Exam Report\n");
		fprintf(yanlis,"Soru");
		for(i=0;i<soru_sayisi;i++){  // for d�ng�s� =i de�erini 0 ata i soru say�s�ndan k���k olana kadar i yi birer birer artt�r.
			fprintf(yanlis,"%d",i+1); // Soru sayilarini yazan d�ng�.
		}
		fprintf(yanlis,"\nAnswer");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%c",cvp_anht[i]); // Cevap anahtarlarini yazan d�ng�.
		}
		fprintf(yanlis,"\nPuan(%c)\n");
		while(fscanf(y,"%d %s",&Numara,&cvp)!=EOF){ //EOF dosyan�n bitti�inin haberini bize vermektedir.
		    double Puan=0; //Puan� double �eklinde atad�m.
			for(i=0;i<soru_sayisi;i++){
				if(cvp_anht[i]==cvp[i])
					Puan++; 
				else
					ynlsr[i]+=1; // ka��r�lan sorular
			}
			int not=(double)100/soru_sayisi * Puan; //Bu i�lem y�zdesel puan� hesaplar.
			fprintf(yanlis,"%1d\n",Numara,not); // Dosyaya ��rencinin notunu yazd�r�r.
		}
		fprintf(yanlis,"\n");
		fprintf(yanlis,"Soru");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%d",i+1); // soru numaras�
		}
		fprintf(yanlis,"\n");
		fprintf(yanlis,"ynlsr ");
		for(i=0;i<soru_sayisi;i++){
			fprintf(yanlis,"%d",ynlsr[i]); //yanl�s yapilan soru say�s�n� verir.
		}
		printf("Report.txt adli dosya olusturuldu");}
	fclose(y);// FILE*y dosyas�n� kapatt�
	fclose(yanlis);// FILE*yanlis dosyas�n� kapatt� 
	}
int main(){
	int n;
	printf("Lutfen baslamak icin bir rakam giriniz: "); 
	scanf("%d",&n);	
	fgetAnswers(); //Bizden istenilen fonksiyonu kapama.
	return 0;
}
