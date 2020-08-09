#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Classbilgi
{
	private:
		string isim;
		string aciklama[100];
		int kullanim;
		int point = 0;
		int blackPoint = 0;
	public:
		void runThis(){
			for(int i = 0;i<100;i++){
				aciklama[i] = ".";
			}
		}
		
		//giriş
		void input(string isimyazisi,string aciklamayazisi){
			bool isimSon = false, aciklamaSon = false;
			string input;
			cout<<endl<<isimyazisi;
			cin>>input;
			isim = input;
			cout<<endl<<aciklamayazisi;
			for(int i = 0;i<100;i++){
				cin>>input;
				if(input==";"){break;}
				aciklama[i]=input;
				cout<<endl<<i;
			}
		}
		
		void print_aciklama(){
			for(int i = 0;i<100;i++){
				if(aciklama[i] != "."){
					cout<<aciklama[i]<<" ";
				}
			}
			cout<<endl;
		}
		
		//isim yazd�rma
		string getir_isim(){
			return isim;
		}
		
		
		//arama
		
		void search(string search[100]){
			for(int i = 0;i<100;i++){
				if(search[i] == "."){
					continue;
				}
				for(int j = 0;j<100;j++){
					if(aciklama[i] == "."){
						continue;
					}
					if(search[i] == aciklama[j]){
						cout<<endl<<isim<<endl;
						point+=1;
						break;
					}
				}
			}
		}
		
		void search2(string search[100]){
			for(int i = 0;i<99;i++){
				if(search[i] == "."){
					continue;
				}for(int j = 0;j<99;j++){
					if(aciklama[i] == "."){
						continue;
					}
					if(search[i] == aciklama[j] and search[i+1] == aciklama[j+1]){
						cout<<endl<<"*"<<isim<<"*"<<endl;
						point+=2;
						break;
					}
				}
			}
		}
		
		void search3(string search[100]){
			for(int i = 0;i<98;i++){
				if(search[i] == "."){
					continue;
				}for(int j = 0;j<98;j++){
					if(aciklama[i] == "."){
						continue;
					}
					if(search[i] == aciklama[j] and search[i+1] == aciklama[j+1] and search[i+2] == aciklama[j+2]){
						cout<<endl<<"**"<<isim<<"**"<<endl;
						point+=3;
						break;
					}
				}
			}
		}
		
		void search4(string search[100]){
			for(int i = 0;i<97;i++){
				if(search[i] == "."){
					continue;
				}for(int j = 0;j<97;j++){
					if(aciklama[i] == "."){
						continue;
					}
					if(search[i] == aciklama[j] and search[i+1] == aciklama[j+1] and search[i+2] == aciklama[j+2] and search[i+3] == aciklama[j+3]){
						cout<<endl<<"***"<<isim<<"***"<<endl;
						point+=4;
						break;
					}
				}
			}
		}
		void setAciklama(string forAciklama,int num){
			aciklama[num] = forAciklama;
		}
		
		void setName(string newName){
			isim = newName;
		}
		
		void setBlackPoint(int newBlackPoint){
			blackPoint = newBlackPoint;
		}
		
		void save(string file){
			file+=".ray";
			ofstream kayit(file,ios::app);
			if(kayit.is_open()){
				kayit<<isim<<" ";
				for(int i = 0;i<100;i++){
					kayit<<aciklama[i]<<" ";
				}kayit<<"; "<<blackPoint<<endl;
			}kayit.close();
		}
		
		int pointReturner(){
			return point;
		}
		
		int blackPointReturner(){
			return blackPoint;
		}
		
		void pointReset(){
			point = 0;
		}
		
		void blackPointPP(){
			blackPoint++;
		}
		
		
};

void mostPoint(Classbilgi bilgi[100]){
	for(int i = 0;i<100;i++){
		for(int j = 99;j>0;j--){
			if(bilgi[i].pointReturner() == j+bilgi[i].blackPointReturner()) {
				cout<<j+bilgi[i].blackPointReturner()<<"!:"<<bilgi[i].getir_isim()<<endl;
			}
		}
	}
	for(int i = 0;i<100;i++){
		bilgi[i].pointReset();
	}
}

void search(Classbilgi bilgi[100]){
	string search[100];
	for(int i=0;i<100;i++){
		search[i] = ".";
	}
	for(int i=0;i<100;i++){
		cin>>search[i];
		if(search[i] == ":"){
			search[i] = ".";
			break;
		}
	}
	cout<<endl<<"Bulunan bilgiler:"<<endl;
	for(int i = 0;i<100;i++){bilgi[i].search(search);}
	for(int i = 0;i<100;i++){bilgi[i].search2(search);}
	for(int i = 0;i<100;i++){bilgi[i].search3(search);}
	for(int i = 0;i<100;i++){bilgi[i].search4(search);}
	mostPoint(bilgi);
	
}


void bilgi100saver(string fileName,Classbilgi bilgi[100]){
	for(int i = 0;i<100;i++){
		bilgi[i].save(fileName);
	}
}

void bilgi100loader(string fileName,Classbilgi bilgi[100]){
	string fromFile;
	ifstream loader(fileName+".ray");
	for(int i = 0;i<100;i++){
		loader>>fromFile;
		bilgi[i].setName(fromFile);
		for(int j = 0;j<100;j++){
			loader>>fromFile;
			if(fromFile == ";"){
				loader>>fromFile;
				bilgi[i].setBlackPoint(stoi(fromFile));
				break;
			}else bilgi[i].setAciklama(fromFile,j);
		}
	}
}

int bilgiBulucu(string isim,Classbilgi bilgi[100]){
	bool buldu = false;
	int bulunan = -1;
	for(int i = 0;i<100;i++){
		if(bilgi[i].getir_isim() == isim){
			bulunan = i;
		}	
	}
	return bulunan;
}

int blankBilgi(Classbilgi bilgi[100]){
	int willReturn = -1;
	for(int i = 0;i<100;i++){
		if(bilgi[i].getir_isim() != "."){
			willReturn = i;
		}
	}
	return willReturn;
}


int main(){
	int bilgiCounter = 0;
	string command;
	Classbilgi bilgi[100];
	for(int i = 0;i<100;i++){
		bilgi[i].runThis();
	}
	
	while(true){
		cout<<endl<<"Bilgi girmek istiyorsan 'gir' bilgiyi aramak istiyorsan 'ara' olan bilginin a��klamas�n� g�rmek istiyorsan 'aciklama' diyebilirsin."<<endl;
		cin>>command;
		if(command == "gir"){
			cout<<endl<<"Bilgiyi su sekil gir:"<<endl<<"girdi�in bilgi : a��klamas� ;"<<endl<<"Bilgiyi ve a��klamas�n� gir:";
			bilgiCounter = blankBilgi(bilgi);
			bilgi[bilgiCounter].input("","");
			bilgiCounter++;
		}else if(command == "ara"){
			search(bilgi);
			cout<<endl<<"Hangisi senin bilgin:";
			cin>>command;
			if(bilgiBulucu(command,bilgi) == -1){
				cout<<endl<<"Boyle bir bilgi yok"<<endl;
			}else{
				cout<<endl<<"Bilgin:"<<endl;
				if(bilgiBulucu(command,bilgi) != -1){
					bilgi[bilgiBulucu(command,bilgi)].print_aciklama();
					bilgi[bilgiBulucu(command,bilgi)].blackPointPP();
					cout<<endl<<"Bu bilginin seviyesi artti:"<<bilgi[bilgiBulucu(command,bilgi)].blackPointReturner()<<endl;
				}
			}
			
		}else if(command == "aciklama"){
			cin>>command;
		}else if(command == "kayit"){
			cin>>command;
			bilgi100saver(command,bilgi);
		}else if(command == "yukle"){
			cin>>command;
			bilgi100loader(command,bilgi);
		}
	}
}
