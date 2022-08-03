/*
	Name: Cyber Security Toolkit

*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int password_generator(){
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>  Password Generator  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	char alpha_num[] = "67ghiST5j8^&:*a07WX@1ef9V2tv34d5wxQR14DOIpkJ8LZl2mMNBC9!noqYEruA#6$sy3zPbcU%FGHK";
	int req_length, string_length = (sizeof(alpha_num) - 1);
	cout << "Enter the Length (>10) of Password: ";
	cin >> req_length;
	while(req_length < 10){
		cout<<"Less than 10 is not allowed!!! \nEnter the Length (>10) of Password:";
		cin >> req_length;
	}
	srand(time(0));
	cout << "\n=> Generated Password of Length "<<req_length<< " is :  ";
	for (int i = 0; i < req_length; i++)
		cout << alpha_num[rand() % string_length];
	string con;
	cout<<"\n\nDo you want to continue this tool? (Y/N): ";
	cin.ignore();
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS");
		password_generator();
	}
	else{
		return 0;
	}
}

int password_analyzer(){
	
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>   Password Analyzer  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	int l_case=0, u_case=0, digit=0, special=0,strength=100;
	string password;
	cin.ignore();
	cout<<"\nEnter your password: ";
	getline(cin, password);
	int len = password.length();
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>      Suggestions     <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	
	if (len <=8 ){
		cout<<"=> Password length is too SHORT"<<endl;
		strength -= 50;
	}
	if (len > 8 && len <=10){
		cout<<"=> Password length could be increased more"<<endl;
		strength -= 25;
	}
	if (len > 20){
		strength += 50;
	}

	for (int i =0 ; i < len ; i++){
		if(islower(password[i]))
      		l_case++;
    	if(isupper(password[i]))
     		u_case++;
    	if(isdigit(password[i]))
      		digit++;
    	if(!isalpha(password[i]) && !isdigit(password[i]) && password[i] != ' ')
      		special++;  
	}
	if (l_case<=2){
		cout<<"=> Add more LOWERcase characters to increase strength!"<<endl;
		strength -= 15;
	}
	if (u_case<=2){
		cout<<"=> Add more UPPERcase characters to increase strength!"<<endl;
		strength -= 15;
	}
	if (digit<=2){
		cout<<"=> Add more DIGITS to increase strength!"<<endl;
		strength -= 15;
	}
	if (special<=2){
		cout<<"=> Add more SPECIAL characters to increase strength!"<<endl;
		strength -= 15;
	}
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>   Password Analyzed  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	cout<<"=> Total Length: "<<len<<endl
		<<"=> Lowercase: "<<l_case<<endl
		<<"=> Uppercase: "<<u_case<<endl
		<<"=> Digits: "<<digit<<endl
		<<"=> Special: "<<special<<endl;
		
	cout<<"\n\t===================================="<<endl;
	cout<<"\t====>>>   Password Strength  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	cout<<strength<<"% |";
	{
	

	for (int i = 0 ; i < int(strength/2) ; i++){
		cout<<"=";
	}
	for (int i = 0 ; i <(100-(strength) )/2; i++){
		cout<<".";
	}

	cout<<"|"<<endl<<endl;
	string con;
	cout<<"Do you want to continue this tool? (Y/N): ";
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS");
		password_analyzer();
	}
	else{
		return 0;
	}
}
}
void encryption(){
	string plain_text;
	plain_text.clear();
	cout<<"Enter the Plain Text: "<<endl;
	cin.ignore();
	getline(cin, plain_text);
	int len = 1;
	for (int i = 0; i<(int) plain_text.length() ; i++){
		plain_text[i] = tolower(plain_text[i]);
		if (plain_text[i]==' '){
			len++;
		}
	}
	string word;
	word.clear();
	string arr[len];
	int j = 0;
	for (int i=0 ; i<(int) plain_text.length();i++){
		
		if (plain_text[i] != ' '){
			word.push_back(plain_text[i]);
		}
		
		if (plain_text[i] == ' '){
			arr[j] = word;

			j++;
			word.clear();
		}
		if (i == (int) plain_text.length()-1){
			arr[j] = word;
		}

	}
	string reversed_arr[len];
	int var1 = 0;
	for (int index = len-1; index>=0 ; index-- ){
		
		reversed_arr[var1] = arr[index];

		var1++;
	}
	string secret_key;
	secret_key.clear();
	cout<<"Enter the Secret key: ";
	cin>>secret_key;
	int numeric_key[secret_key.length()-1];
	for (int i= 0 ; i < (int) secret_key.length() ; i++) {
		numeric_key[i] = int(secret_key[i]) - 96;
	}
	cout<<endl;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string var2;
	int num = 0;
	string cyphertext;
	for (int l = 0 ; l < len ; l++){
		
		var2 = reversed_arr[l];
		int no = l;
		if (no>(int)(secret_key.length()-1)){
			no = no-secret_key.length();
		}
		for (int j = 0 ; j<= (int) var2.length() ; j++){
			if (isalpha(var2[j])){
				
				num = int(var2[j]) - 96;
				
				num += int(numeric_key[no]);
				if (num>26){
					num = num - 26;
				}
				var2[j] = alphabet[num-1];
		}
			var2[j] = var2[j];
			num = 0;
		}
		
		cyphertext.append(var2);
		cyphertext.append(" ");
	}
	cout<<"Cypher Text: "<<cyphertext;
}

void decryption(){
	string cypher_text;
	cout<<"Enter the Cypher Text: "<<endl;
	cin.ignore();
	getline(cin, cypher_text);
	int len = 1;
	for (int i = 0; i<(int)cypher_text.length() ; i++){
		if (cypher_text[i]==' '){
			len++;
		}
	}
	
	string word;
	string arr[len];
	int j = 0;
	for (int i=0 ; i<(int)cypher_text.length();i++){
		
		if (cypher_text[i] != ' '){
			word.push_back(cypher_text[i]);
		}
		
		if (cypher_text[i] == ' '){
			arr[j] = word;
			j++;
			word.clear();
		}
		if (i == (int) cypher_text.length()-1){
			arr[j] = word;
		}
		
		
	}

	string secret_key;

	cout<<"Enter the Secret key: ";
	cin>>secret_key;
	int numeric_key[secret_key.length()-1];
	for (int i= 0 ; i < (int) secret_key.length() ; i++) {
		numeric_key[i] = int(secret_key[i]) - 96;
	}
	cout<<endl;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string var2;
	int num;
	string plain_text;
	plain_text.clear();
	string arr2[len];
	for (int l = 0 ; l < len ; l++){
		
		var2 = arr[l];
		int no = l;
		if (no>(int) (secret_key.length()-1)){
			no = (no-secret_key.length());
		}
		for (int j = 0 ; j<=(int) var2.length() ; j++){
			if (isalpha(var2[j])){
				
				num = int(var2[j]) - 96;
				
				num -= int(numeric_key[no]);
				if (num<=0){
					num += 26;
				}

				var2[j] = alphabet[num-1];
		}
			var2[j] = var2[j];
			num = 0;
		}
		
		arr2[l] = var2;
	}
	
	string reversed_arr[len];
	int var1 = 0;
	for (int index = len-1; index>=0 ; index-- ){

		reversed_arr[var1] = arr2[index];

		var1++;
	}
	
	for (int index = 0; index<len ; index++ ){
		plain_text.append(reversed_arr[index]);
		plain_text.append(" ");
	}

	cout<<"Plain Text: "<<plain_text;
}

int cryptography_tool(){
	
	cout<<"\t===================================="<<endl;
	cout<<"\t====>>>  Cryptographic Tool  <<<===="<<endl;
	cout<<"\t===================================="<<endl;
	long what;
	cout<<"What do you want to perform? "<<endl
	<<"1) Encryption "<<endl
	<<"2) Decryption "<<endl
	<<"=>";
	cin>>what;
	while (what<1 && what>2){
		cout<<"Invalid Option"<<endl;
		cin>>what;
	}
	switch (what){
		case 1:
			encryption();
			break;
		case 2:
			decryption();
			break;
		default:
			cout<<"Invalid Option";
	}
	string con;
	cout<<"\nDo you want to continue this tool? (Y/N): ";
	cin.ignore();
	getline(cin, con);
	if (con == "Y" || con=="y"){
		system("CLS");
		cryptography_tool();
	}
	else{
		return 0;
	}
}
int main(){
	cout<<"\t========================================"<<endl
	    <<"\t====>>>  Cyber Security Toolkit  <<<===="<<
	endl<<"\t========================================\n"<<endl;
	int what;
	cout<<"1) Cryptography Tool"<<endl
	<<"2) Password Analyzer"<<endl
	<<"3) Password Generator"<<endl
	<<"4) Exit"<<endl
	<<"=> ";
	cin>>what;
	while(what<1 || what >4){
		cout<<"Error!!! Invalid Option Selected"<<endl;
		cout<<"Please choose a correct option (1-4): ";
		cin>>what;
	}
	switch(what){
		case 1:
			system("CLS");
			cryptography_tool();
			break;
		case 2:
			system("CLS");
			password_analyzer();
			break;
		case 3:
			system("CLS");
			password_generator();
			break;
		case 4:
			cout<<"Thanks for using :)"<<endl;
			cout<<"Exiting......."<<endl;
			return 0;
		default:
			cout<<"Something Went Wrong!"<<endl;
	}
	system("CLS");
	main();
	return 0;
}
