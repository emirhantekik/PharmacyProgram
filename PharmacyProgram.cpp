#include <iostream>
#include <fstream>//dosyaya yaz� yazmak i�in
#include <string>
//#include <conio.h>
#include <cstring>//strcat strcpy i�in kullan�lacak

using namespace std;

class Eczane{
	
	public:
		
		void dosyayaYaz(const Eczane& e);
		void dosyaAramaEczane(const Eczane& e);
		
		//yeni eczane olu�turmak i�in//
		void eczane_olustur(){
			Eczane e;
			getDataEczane() ;
		}
		
		void getDataEczane(){
		
			cout<<"eczane adi:";
			cin>>eczane_isim;
		
			cout<<"eczane id:";
			cin>>eczane_id;
		
			cout<<"eczane adres:";
			cin.ignore( );
			cin>>eczane_adres;	
		}
		/*------------------------------*/
		/*eczane olu�turmak ve ilaclar i�in ayr� bir dosya a�mak i�in yeniden olu�turuldu*/
		/*
		Yeniden olu�turulmas�n�n sebebi 1.1 se�ilirken mainde eczane ad� al�n�p ilac i�in ba�ak bir stringe kopyalan�p yap�l�yordu.
		A�a��da void eczane_olusturYeni(char* tempChar) fonksiyonunda mainden al�nan eczane ismi char* ile fonksiyona at�l�p stringe �evriliyor
		ve getDataEczaneYeni fonksiyonuna bu string at�l�p objenin eczane_isim ��esine e�itleniyor.
		*/
		void eczane_olusturYeni(char* tempChar){
			string isimm=string(tempChar);
			Eczane e;
			getDataEczaneYeni(isimm);
		}
		
		void getDataEczaneYeni(string isim){
			
			eczane_isim=isim;
			
			cout<<"eczane id:";
			cin>>eczane_id;
		
			cout<<"eczane adres:";
			cin.ignore( );
			cin>>eczane_adres;	
		}
		/*-------------------------------------*/
	//**********************************//
		Eczane(){//DEFAULT CONSTRUCTOR
		
			eczane_id=0;
			eczane_isim="Bilgi yok";
			eczane_adres="Bilgi yok" ;
			
		}
		
		Eczane(int id,string isim,string adres){
			
			eczane_id=id;
			eczane_isim=isim;
			eczane_adres=adres;
			
		}
		
		Eczane(const Eczane& other){//copy constructor
			eczane_id=other.eczane_id;
			eczane_isim=other.eczane_isim;
			eczane_adres=other.eczane_adres;
		}
		
		Eczane& operator=(const Eczane& other){//assignment constructor
			eczane_id=other.eczane_id;
			eczane_isim=other.eczane_isim;
			eczane_adres=other.eczane_adres;
			return *this;
		}
		
		void Print(){
			cout<<"Eczane bilgiler : "<<eczane_id<<","<<eczane_isim<<","<<eczane_adres<<endl;
		}
		
		/*ECZANEN�N SET FONKS�YONLARI*/
		void seteczaneid(int id){eczane_id=id ;} 
		void seteczaneisim(string isim){eczane_isim=isim ;} 
		void seteczaneadres(string adres){eczane_adres=adres ;}
		/*-----------------------------------*/
		
		/*ECZANEN�N GET FONKS�YONLARI*/
		int geteczaneid(){return eczane_id ;} 
		string geteczaneisim(){return eczane_isim ;} 
		string geteczaneadres(){return eczane_adres ;}
		/*-----------------------------------*/
		
	private:
		
		int eczane_id;
		string eczane_isim;
		string eczane_adres;
		
};

class Ilac{

	private:
	
		int ilac_id;
		int ilac_sayisi;
		double ilac_fiyati;
		string ilac_isim;
	
	public:
		void dosyayaYazIlac(char* tempChar,const Ilac& i);
		void dosyayaYazIlacYeni(char* tempChar,const Ilac&i);
		//ila� eklemek i�in//
		void ilac_olustur(){
			Ilac i;
			getDataIlac() ;
		}
		
		void ilacOlusturmaDosyayaYazma(char* tempChar,const Ilac& i){
			Ilac ilac;
			getDataIlac();
			
			fstream dosya;
			strcat(tempChar,".dat") ;
			dosya.open(tempChar,ios::out|ios::app);
			dosya<<this->ilac_isim<<"\t"<<this->ilac_id<<"\t"<<this->ilac_fiyati<<"\t"<<this->ilac_sayisi<<endl;
			cout<<"\nilac yazma islemi basariyla gerceklestirildi" ;
		}
		
		void getDataIlac(){
		
			cout<<"ilac adi:";
			cin>>ilac_isim;
		
			cout<<"ilac id:";
			cin>>ilac_id;
		
			cout<<"ilac fiyati:";
			cin>>ilac_fiyati;	
			
			cout<<"ilac sayisi:";
			cin>>ilac_sayisi;
		}
		//----------------------------//
		
		Ilac(){//default
			ilac_id=0;
			ilac_sayisi=0;
			ilac_fiyati=0.0;
			ilac_isim="Bilgi yok" ;
		}
		Ilac(int id,int sayi,double fiyat,string isim){//constructor
			ilac_id=id;
			ilac_sayisi=sayi;
			ilac_fiyati=fiyat;
			ilac_isim=isim;
		}
		
		Ilac(const Ilac& other){//copy constructor
			
			ilac_id=other.ilac_id;
			ilac_sayisi=other.ilac_sayisi;
			ilac_fiyati=other.ilac_fiyati;
			ilac_isim=other.ilac_isim;
			
		}
		
		Ilac& operator=(const Ilac& other){//aissignment constructor
			ilac_id=other.ilac_id;
			ilac_sayisi=other.ilac_sayisi;
			ilac_fiyati=other.ilac_fiyati;
			ilac_isim=other.ilac_isim;
			return *this;
		}
		
		/*�LA�LARIN SET FONKS�YONLARI*/
		void setIlac_id(int id){ilac_id=id ;} 
		void setIlac_fiyat(double fiyat){ilac_fiyati=fiyat ;} 
		void setIlac_sayi(int sayi){ilac_sayisi=sayi ;}
		void setIlac_isim(string isim){ilac_isim=isim ;} 
		/*-----------------------------------*/
		
		/*�LA�LARIN GET FONKS�YONLARI*/
		int getIlac_id(){return ilac_id ;} 
		int getIlac_fiyat(){return ilac_sayisi ;} 
		double getIlac_sayi(){return ilac_fiyati ;}
		string getIlac_isim(){return ilac_isim; }
		/*-----------------------------------*/
};

void eczanelerdenIlacArama(){
	
	cout<<"\nDosya okundu\n"<<endl;
	ifstream dosya1("eczane_listesi.dat");
	string metinEczane;
	string metinIlac;
	char okuEczane[20];
	char okuIlac[20];
	if(dosya1.is_open()){
		
	char arama[20];
	cout<<"Aradiginiz ilaci giriniz :\n";
	cin>>arama;
	cout<<endl;
		
		//getline sat�r sat�r okurken metin dosyas�na sat�r� aktar�yor. Aktar�lm�� sat�rdan Eczane isimini chara al�p dosyas�n� bulup ilac� arat�caz
		while(getline(dosya1,metinEczane)){
			strcpy(okuEczane,metinEczane.c_str());//sat�r� oku char�na kopyalad�.
			strtok(okuEczane,"\t");//Dosyada ilk isim yazd�r�ld��� i�in ba�lang��tan "\t" kadar eczanenin ismini al�r
			/*Buraya kadar dosyada bulunan eczanenin ad� al�nd�.*/
			
			string eczane=string(okuEczane);
			strcat(okuEczane,"_ilac.dat");
			fstream dosya2;
			dosya2.open(okuEczane,ios::in);
			if(dosya2.is_open()){
				
				while(getline(dosya2,metinIlac)){
					strcpy(okuIlac,metinIlac.c_str());
					strtok(okuIlac,"\t");
					//Stringleri kar��la�t�r�p varsa ilac�n �zellikleri ekrana yazd�r�lacak//
					string okuIlac1;
					string arama1;
					/*-----------------------------------------------------------------------*/
					okuIlac1=string(okuIlac);//stringe �evirildi
					arama1=string(arama);//stringe �evrildi
					
					if(arama1==okuIlac1)/*iki string kar��lla�t�r�ld�*/{
					cout<<"Aradiginiz ilac "<<arama<<" "<<eczane<<" eczanesinde bulunmaktadir."<<endl;
						cout<<"Ilac bilgileri : "<<metinIlac<<endl;
					}
				}
				
			}
		}
		
	}
	else cout<<"Dosya acilamadi!!!\n";
	
}
/*------------------------------------------------------------------------------------------------------------*/


void dosyadaIlacDegistirme(char* charTemp){
	
	string deleteLine;
	string line;
	
	ifstream dosya;
	dosya.open(charTemp,ios::in);
	ofstream temp;
	temp.open("temp.dat");
	cout<<"\nHangi ilacin bulundugu satiri degistirmek istiyorsunuz : ";
	cout<<"\nLutfen yukarida bulunan bilgileri dogru yazarak giriniz!!!";
	cin>>deleteLine;
	
	while (getline(dosya,line)){
    	if (line != deleteLine){
    		temp << line << endl;
    	}
	}
	temp.close();
	dosya.close();
	remove(charTemp);
	rename("temp.txt",charTemp);
}//fonksiyon sonu

//m��terinin arad��� eczanenin dosyas�nda bulunan ila�lar�n listesini ekrana basar//
void ilacYazdirma(char* tempChar){//Ekrana dosyadaki ilaclar� yazd�r�r.
	
	string eczane=string(tempChar);//128. sat�rda eczanenin ad�n� yazd�rmak i�in kullan�ld�.
	strcat(tempChar,"_ilac.dat");
	fstream file;
	file.open(tempChar,ios::in);
	string metin;
	cout<<endl<<eczane<<"eczanesinde bulunan ilaclarin listesi :"<<endl<<endl;
	cout<<"ilac  "<<"\t"<<"id"<<"\t"<<"fiyat "<<"\t"<<"adet"<<endl;
	cout<<"----------------------------"<<endl;
	while(getline(file,metin)) {
		cout<<metin<<"\n";
	}
	
}
/*-------------------------------------------------------------------------------------*/

void Ilac::dosyayaYazIlacYeni(char* tempChar,const Ilac&i){
	fstream dosya;
	dosya.open(tempChar,ios::out|ios::app);
	dosya<<this->ilac_isim<<"\t"<<this->ilac_id<<"\t"<<this->ilac_fiyati<<"\t"<<this->ilac_sayisi<<endl;
	cout<<"\nilac yazma islemi basariyla gerceklestirildi\n\n" ;
}

void Ilac::dosyayaYazIlac(char* tempChar,const Ilac& i){
	
	fstream dosya;
	strcat(tempChar,"_ilac.dat") ;
	dosya.open(tempChar,ios::out|ios::app);
	dosya<<this->ilac_isim<<"\t"<<this->ilac_id<<"\t"<<this->ilac_fiyati<<"\t"<<this->ilac_sayisi<<endl;
	cout<<"\nilac yazma islemi basariyla gerceklestirildi\n\n" ;
}

//dosyadan eczane listesini okuma fonksiyonu
void dosyadaneczaneokuma() {
	
	cout<<"\n\nDosya okundu\n"<<endl;
	ifstream dosya1("eczane_listesi.dat");
	string metin;
	while(getline(dosya1,metin)){
		cout<<metin<<"\n";
	}
	
}
/*-------------------------------------------*/

void dosyaAramaEczane(){
	
	fstream dosya;
	dosya.open("eczane_listesi.dat",ios::in);
	string arama;
	string ad;
	int x=0;
	cout<<"Aradiginiz eczanenin adini giriniz :";
	cin>>arama;
	if(dosya.is_open()){
		int x=0;
		do{
			dosya>>ad;
			if(ad==arama){
				cout<<arama<<" eczanesi bilgileri :"<<endl;
				cout<<"\t"<<"ID"<<"\t"<<"Adres"<<endl;
				getline(dosya,ad);
				cout<<ad<<endl; 
				x=1; }//if sonu
		}/*do sonu*/while(!dosya.eof());
		dosya.close();
		if(x==0) cout<<"\nAradiginiz eczanenin dosyada kaydi yok!!!\n"<<endl;
	}//ilk if sonu
	else cout<<"Dosya acilamadi"<<endl;
}

void Eczane::dosyayaYaz(const Eczane& e){
	
	fstream dosya;
	dosya.open("eczane_listesi.dat",ios::out|ios::app);
	dosya<<this->eczane_isim<<"\t"<<this->eczane_id<<"\t"<<this->eczane_adres<<endl;
	cout<<"\nYazma islemi basariyla gerceklestirildi\n\n";
}

/*	Menuler	*/
void anaMenu() {
	
	cout<<"1. Eczane girisi"<<endl;
	cout<<"2. Musteri girisi"<<endl;
	
}

void eczaneMenu() {
	
	cout<<"1.1. Eczane Listesi olustur"<<endl;
	cout<<"1.2. Eczane Ekle"<<endl;
	cout<<"1.3. Ilac Ekle"<<endl;
	cout<<"1.4. Ilac Duzenle"<<endl;

}

void musteriMenu() {
	
	cout<<"2.1. Ilac Ara"<<endl;
	cout<<"2.2. Eczane Listesi"<<endl;
	cout<<"2.3. Herhangi Bir Eczaneyi Goster"<<endl;
	cout<<"2.4. Herhangi Bir Eczaneye Ait Ilac Listesi"<<endl;
	
}
/*---------------------------------------------------------------------------*/

int main() {
	/*Tan�mlan�lan eczaneler*/
	Eczane eczane1(1,"Faruk","Istanbul Esenler");
	Eczane eczane2(2,"Mahir","Istanbul Besiktas");
	Eczane eczane3(3,"Sevil","Istanbul tuzla");
	/*----------------------------------------------------*/
	
	/*									�ylesine �al��ma ileride belki laz�m olur
	Eczane eczane5;
	string a=eczane4.geteczaneisim();
	eczane5.seteczaneisim(a) ;
	eczane5.Print();
	*/
	
	/*Eczane i�in dosya olu�turma ve Dosyaya yazd�rma*/
	ofstream dosya("eczane_listesi.dat") ;
	
	dosya<<eczane1.geteczaneisim()<<"\t"<<eczane1.geteczaneid()<<"\t"<<eczane1.geteczaneadres()<<"\n"<<
		   eczane2.geteczaneisim()<<"\t"<<eczane2.geteczaneid()<<"\t"<<eczane2.geteczaneadres()<<"\n"<<
		   eczane3.geteczaneisim()<<"\t"<<eczane3.geteczaneid()<<"\t"<<eczane3.geteczaneadres()<<endl;
	/*-----------------------------------------------------------------------------------------------------------------------------------*/
	/**/
	Ilac ilac1(1,24,2.25,"Diovan");
	Ilac ilac2(2,5,13.5,"TOBREX");
	Ilac ilac3(3,7,10.24,"Aferin+") ;
	Ilac ilac4(4,14,12.47,"Exelon ") ;
	/*------------------------------------------------------*/
	/*Faruk eczanesi i�in ila� listesi*/
	ofstream dosya1("Faruk_ilac.dat") ;
	dosya1<<ilac1.getIlac_isim()<<"\t"<<ilac1.getIlac_id()<<"\t"<<ilac1.getIlac_sayi()<<"\t"<<ilac1.getIlac_fiyat()<<"\n"<<
		    ilac2.getIlac_isim()<<"\t"<<ilac2.getIlac_id()<<"\t"<<ilac2.getIlac_sayi()<<"\t"<<ilac2.getIlac_fiyat()<<"\n"<<
		    ilac3.getIlac_isim()<<"\t"<<ilac3.getIlac_id()<<"\t"<<ilac3.getIlac_sayi()<<"\t"<<ilac3.getIlac_fiyat()<<"\n"<<
		    ilac4.getIlac_isim()<<"\t"<<ilac4.getIlac_id()<<"\t"<<ilac4.getIlac_sayi()<<"\t"<<ilac4.getIlac_fiyat()<<endl;
	/*-------------------------------------------------------------------------------------------------------------------------------------*/
	
	/*Mahir eczanesi i�in ila�lar�n listesi*/
	ofstream dosya2("Mahir_ilac.dat");
	dosya2<<ilac1.getIlac_isim()<<"\t"<<ilac1.getIlac_id()<<"\t"<<ilac1.getIlac_sayi()<<"\t"<<ilac1.getIlac_fiyat()<<"\n"<<
		    ilac2.getIlac_isim()<<"\t"<<ilac2.getIlac_id()<<"\t"<<ilac2.getIlac_sayi()<<"\t"<<ilac2.getIlac_fiyat()<<"\n"<<
		    ilac4.getIlac_isim()<<"\t"<<ilac4.getIlac_id()<<"\t"<<ilac4.getIlac_sayi()<<"\t"<<ilac4.getIlac_fiyat()<<endl;
	/*-------------------------------------------------------------------------------------------------------------------------------------*/
	
	/*Sevil eczanesi i�in ila�lar�n listesi*/
	ofstream dosya3("Sevil_ilac.dat");
	dosya3<<ilac1.getIlac_isim()<<"\t"<<ilac1.getIlac_id()<<"\t"<<ilac1.getIlac_sayi()<<"\t"<<ilac1.getIlac_fiyat()<<"\n"<<
		    ilac2.getIlac_isim()<<"\t"<<ilac2.getIlac_id()<<"\t"<<ilac2.getIlac_sayi()<<"\t"<<ilac2.getIlac_fiyat()<<endl;
	/*-------------------------------------------------------------------------------------------------------------------------------------*/
	donn:
	cout<<"Ana menuye hosgeldiniz..."<<endl<<endl;
	geridon://Eczane girisinde sifre yanl�� girilirse bu kod sat�r�na geri d�necek
	anaMenu() ;
	
	int islem;//Ana menude yap�lacak i�lemi se�mek i�in
	int islem1;//Eczane Menusunde yap�alcak islemi secmek i�in
	int islem2;//Musteri Menusunde yap�lacak islemi secmek i�in
	
	int sifre=1234;//eczane sifresi
	
	char metin1[20];//eczaneden ilac aramak i�in g�nderilecek parametre
	char metin2[20];//ilac eklerken sonradan dosyay� okumak icin kullan�lan parametre
	char metin3[20];
	string metin;
	
	string cevap;
	string cevapK="y";
	string cevapKK="Y";
	//ifstream dosya1("eczane_listesi.dat"); //GEREKS�Z GAL�BA
	
	Eczane ecz;//eczane eklemek i�in yeni ecz objesi olu�turuldu.
	char ch;
	
	Ilac ilc;//ila� eklemek i�in yeni ilc objesi olu�turuldu.
	
	cout<<endl<<"Lutfen secmek istediginiz islemi giriniz : "<<endl;
	cin>>islem;
	
	switch(islem){
		
		case 1:
			cout<<"Sifre : 1234\n";
			cout<<"Lutfen Sistemde kayitli olan sifreyi giriniz : ";
			int eczanesifre;
			cin>>eczanesifre;

			if(eczanesifre==sifre){}
			
			else{
				system("cls") ;
				cout<<endl<<"Yanlis sifre girdiniz!!!"<<endl<<endl;
				goto geridon;
				
			}
			
			system("cls") ;
			cout<<"Girdiginiz sifre dogrudur..."<<"\n";
			cout<<endl<<"Eczane Menusune hosgeldiniz..."<<endl<<endl;
			eczaneMenu() ;
			
			cout<<"\nLutfen yapmak istediginiz islemi giriniz :"<<endl;
			cin>>islem1;
			
				switch(islem1){
					
					case 1:
						
						cout<<"Eczanenizin adini giriniz : (lutfen sonuna eczane yazmayin. ornegi Emirhan)"<<endl;
						cin>>metin1;
						strcpy(metin2,metin1);
						ecz.eczane_olusturYeni(metin1);
						ecz.dosyayaYaz(ecz);
						ilc.ilac_olustur();
						ilc.dosyayaYazIlac(metin1,ilc);
						geridonn:
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							ilc.ilac_olustur();
							ilc.dosyayaYazIlacYeni(metin1,ilc);
							goto geridonn;
						}
						else
						ilacYazdirma(metin2);
						
						break;
						
					case 2:
						
						ecz.eczane_olustur();
						ecz.dosyayaYaz(ecz);
						dosyadaneczaneokuma();
						//ba�ka i�lem yapmak i�in
						cout<<"\nBaska islem yapmak istiyor musunuz: (y/n)\n";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						break;
					
					case 3:
						
						cout<<"Hangi eczanenin ilac listesini ilac eklemek istiyorsunuz:";
						cin>>metin1;
						strcpy(metin2,metin1);
						ilc.ilac_olustur();
						
						ilc.dosyayaYazIlac(metin1,ilc);
						ilacYazdirma(metin2);
						//ba�ka i�lem yapmak i�in
						cout<<"\nBaska islem yapmak istiyor musunuz: (y/n)\n";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						break;
						
					case 4:
						
						cout<<"Hangi eczanenin ilac listesini degistirmek istiyorsunuz:";
						cin>>metin1;
						ilacYazdirma(metin1);
						dosyadaIlacDegistirme(metin1);
						//ba�ka i�lem yapmak i�in
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						break;
												
					Default:
						cout<<"Lutfen dogru islem giriniz!!!";
						goto geridon;
						break;
				}
			
			break;//anamenu switch case 1 sonu
			
		case 2:
			system("cls") ;
			cout<<endl<<"Musteri Menusunu secitiniz.."<<endl<<endl;
			musteriMenu() ;
			
			cout<<"\nLutfen yapmak istediginiz islemi giriniz :"<<endl;
			cin>>islem2;
			
				switch(islem2){
					
					case 1:
						
						eczanelerdenIlacArama();
						//ba�ka i�lem yapmak i�in
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						
						break;
						
					case 2:
						cout<<"\nKayitli eczanelerin listesi";
						dosyadaneczaneokuma() ;
						//ba�ka i�lem yapmak i�in
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						
						break;
						
					case 3:
						
						dosyaAramaEczane();
						//ba�ka i�lem yapmak i�in
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						break;
						
					case 4:
						
						cout<<"Hangi eczanenin ilac listesini gormek istiyorsunuz:";
						cin>>metin1;
						ilacYazdirma(metin1);
						//ba�ka i�lem yapmak i�in
						cout<<"Baska islem yapmak istiyor musunuz: (y/n)";
						cin>>cevap;
						if(cevap==cevapK||cevap==cevapKK){
							goto geridon;
						}
						break;
					
					default:
						
						break;
					
				}
			
			break; // anamenu switch case 2 sonu
		
		default :
			cout<<"Lutfen dogru islem seciniz!!!\n\n";
			goto geridon;
			break;
		
	}
	//switch case sonu//
	//---------------------------------------------------------------------------//
	
	
	
	return 0;
}

