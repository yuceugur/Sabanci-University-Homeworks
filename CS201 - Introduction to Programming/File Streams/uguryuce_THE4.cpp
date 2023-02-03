#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "strutils.h"
//uguryuce-27981 the4
using namespace std;

bool qrFileOpen(ifstream &input, string filename)
{
	input.open(filename.c_str());
	if (input.fail())
	{
		return false;
	}
	return true;
}

bool priceFileOpen(ifstream &input, string filename)
{
	input.open(filename.c_str());
	if (input.fail())
	{
		return false;
	}
	return true;
}


void shortspace(const int & item_count){
	if (item_count / 10 != 0){
		cout << " ";
	}
	else{
		cout << "  ";
	}
}

void longpspace(string & pro_name, double & item_pr, int & our_len){
	int len_pro_name = pro_name.length();
	int lim_space = our_len - (len_pro_name + tostring(item_pr).length() + 4);
	for (int x=0; x < lim_space; x++){
		cout << " ";
	}
}

double vat(double & item_pr){
	double tax_cons = 0.18;
	double tax = item_pr * tax_cons;
	return tax;
}

void printline(double & tax_total,int & our_len){
	cout << "VAT(18%):";
	string our_vat = "VAT(18%):";
	int lim_space = our_len - (our_vat.length() + tostring(tax_total).length());
	for (int x=0; x < lim_space; x++){
		cout << " ";
	}
	cout << tax_total;
	cout << endl;
}

void printline2(double & vat_total_price,int & our_len){
	cout << "Total:";
	string our_total = "Total:";
	int lim_space = our_len - (tostring(vat_total_price).length() + our_total.length());
	for (int x=0; x < lim_space; x++){
		cout << " ";
	}
	cout << vat_total_price;
	cout << endl;
}

void printlast_line(int & our_len){
	for (int x=0; x < our_len+3; x++){
		cout << "_";
	}
	cout << endl;
}

int main()
{
	string qrFile, priceFile, shopFile;
	ifstream input_qr, input_price, input_shop;
	string line_shop, qr_shop,line_qr,qr_qr,prod_name = "",line_price,qr_price,prod_name_input;
	int qr_item;
	double price_price,total_price;
	double total_tax = 0, vat_total_price = 0;
	string line_example = "Coca Cola (330ml) *  5			       6.15";
	int our_len = line_example.length();
	cout << "Please enter a filename for QR database: ";
	cin >> qrFile;
	
	while(!qrFileOpen(input_qr, qrFile))
		{
			cout << endl << "The QR file does not exists" << endl;
			cout << "Please enter a filename for QR database: ";
			cin >> qrFile;
		}

	cout << endl << "Please enter a filename for Price database: ";
	cin >> priceFile;

	while(!priceFileOpen(input_price, priceFile))
		{
			cout << endl << "The Price file does not exists" << endl;
			cout << "Please enter a filename for Price database: ";
			cin >> priceFile;
		}

	cout << endl << "Please enter a filename for your shopping list: ";
	cin >> shopFile;
	cout << endl;
	input_shop.open(shopFile.c_str());
	while (getline(input_shop,line_shop)){
		istringstream input_shop2(line_shop);
		input_shop2 >> qr_shop >> qr_item;
		ToLower(qr_shop);
		for(;getline(input_qr,line_qr);){
			istringstream input_qr2(line_qr);
			input_qr2 >> qr_qr;
			ToLower(qr_qr);
			if (qr_qr == qr_shop){
				while (input_qr2 >> prod_name_input){
					prod_name += prod_name_input + " ";

				}	
				while (getline(input_price,line_price)){
					istringstream input_price2(line_price);
					input_price2 >> qr_price;
					ToLower(qr_price);
					if (qr_price == qr_shop){
						input_price2 >> price_price;
						total_price = qr_item * price_price;
						vat_total_price += total_price;
						cout << prod_name << "*";
						shortspace(qr_item);
						cout << qr_item;
						longpspace(prod_name, total_price,our_len);
						cout << total_price << endl;
						prod_name = "";
						total_tax += vat(total_price);


					}
				}
				input_price.clear();
				input_price.seekg(0);
			}
		}
		input_qr.clear();
		input_qr.seekg(0);
	}
	cout << endl;
	vat_total_price += total_tax;
	printline(total_tax,our_len);
	printlast_line(our_len);
	printline2(vat_total_price,our_len);
	return 0;
}