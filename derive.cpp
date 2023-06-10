#include <stdio.h>
/* signe moins + .conversion est decrementation dynamique dans un autre int et un autre pour le produit*/
int length(char c[50]){
	int i=-1;
	do{
		
		i++;
	}while(c[i]!='\0');
	return i;
}
int checkup(char tab[50],char c[50]){
	int i=-1;
	int ok=0;
do{
	i++;
	for(int j=0;j<10;j++){
	
	if(c[i]==tab[j]){
		ok=1;
	}}
}while((c[i]!='\0')&&(ok==0));
return ok;
}

int conversion(char c[50],int *p){
	int k=1;
	*p=0;
	for(int i=0;i<length(c);i++){
		*p+=((int)c[length(c)-i-1]-(int)'0')*k;
		if(c[length(c)-i-1]=='-'){
			*p-=((int)'-'-(int)'0')*k;
			*p*=-1;
		}
		k*=10;
	}}
	
	
int ext(char c[50],char r[50]){
int k=0,l=0;
for(int i=0;i<length(c);i++){
	l=0;
if(c[i]=='^'){
	do{
		r[k]=c[i+1+l];
		k++;l++;
	}while(c[l+i+1]!='+'&&c[l+i+1]!='-'&&i+l+1<length(c));
	r[k]=' ';
	k++;
	
}
else if(c[i]=='x'&&c[i+1]!='^'){
	r[k]='1';
	k++;
}
}
	r[k]=' ';
	r[k+1]='\0';
	if(r[length(r)-1]==' '&&r[length(r)-2]==' '){
		
	r[length(r)-1]='\0';
	}
}




int extc(char c[50],char r[50]){
	int k=0,checker=0,bb=0;
			checker=1;
	for(int i=0;i<length(c);i++){
		if (checker==1){
		
		if(c[i]!='x'&&c[i]!='+'&&c[i]!='-'&&c[i]!='^'){
			r[k]=c[i];
			k++;}
		else if(c[i]=='x'&&(c[i-1]=='+'||c[i-1]=='-'||i==0)){
			
			r[k]='1';
			checker=1;
			k++;
		}}
		 if(checker==1&&c[i-1]=='x'){
			checker=0;
		}
		 if(c[i]=='+'||c[i]=='-'&&i!=0){
			checker=1;
			r[k]=' ';
			
			k++;
		}
	}
	r[k]=' ';
	r[k+1]='\0';
	if(r[length(r)-1]==' '&&r[length(r)-2]==' '){
		
	r[length(r)-1]='\0';
	}
}









int main(){
	char r[50],c[50];
	char co[50]={'0','1','2','3','4','5','6','7','8','9'};
	char fct[50];
	char derv[50];
	char aux[30];
	int tc,tp;int w;
		
do{w=0;
	int k=0;
fct[0]='\0';r[0]='\0';
c[0]='\0';
	do{
		puts("\n Provide the polynomial expression (from high to low factor and ctes afterwards otherwise errors will pop up)");
		puts(" example: 7x^10+5x^3+x+19");
		gets(fct);
	}while(fct[0]=='\0');
	printf("p(x)= ");
	puts(fct);
	printf("\np'(x)= ");
	ext(fct,r);
	extc(fct,c);
	int i=0,m=1;int l;
	k=0;
	if(r[1]=='\0'&&r[0]==' '){
		printf("0");
		goto v;
	}
	if(fct[0]=='-'){
			printf("%c",'-');
		}	
	do{
		
		tc=0, l=0,m=1;
		do{
			aux[l]=c[i];
			l++;
			i++;
			
		}while(c[i]!=' ');
		aux[l]='\0';
		conversion(aux,&tc);
	tp=0,l=0,m=1;aux[0]='\0';
		do{
			aux[l]=r[k];
			l++;
			k++;
		}while(r[k]!=' ');
		aux[l]='\0';
		conversion(aux,&tp);
		
		printf("%d",tc*tp);
		do{
			if((fct[w]=='x')&&(fct[w+1]=='^')){
				printf("%c",fct[w]);
				printf("%c",fct[w+1]);
			}
			w++;
		}while(fct[w-1]!='x');
		if(tp-1!=0){
		printf("%d",tp-1);
		}
		else if (tp-1==0&&fct[w]=='^') {
			printf("%d",1);
		}
		i++;k++;
		char tmp[1];
		do{
			w++;
			tmp[0]=fct[w];
		}while(fct[w]!='+'&&fct[w]!='-'&&w<length(fct));
		tmp[1]='\0';
		if((tmp[0]=='+'||tmp[0]=='-')&&r[i+1]!='\0'){printf("%c",tmp[0]);
		}
	}while(r[i+1]!='\0');
v:int ok=0;
	do{
		printf("\nDo you want to proceede : ok(1) exist(0)\n");
		scanf("%d",&ok);
	}while(ok!=0&&ok!=1);if(!ok)goto e;
}while(1);e:puts("BYE <3");
}
