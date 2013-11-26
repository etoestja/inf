#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

long double eps=1e-7;
long double float_eps=2.220446049250313e-16;
const unsigned int m=4;
long double k[m],d[m-1],rf[m-1];
unsigned int rf_c=0;
long double interval=1010;
long double roots[m-1];

void get_coeffs_2(long double*);
void get_coeffs_3(long double*);
void derivative();
long double abs(long double);
void print_coeffs(long double*,unsigned int);
void find(long double*,unsigned int,long double,long double);
short int sgn(long double*,unsigned int,long double);
long double power(long double,unsigned int);

void print_roots();

//ax^3+bx^2+cx+d

int main() {
	unsigned int i;
	/*for(i=0;i<m-1;i++) {
		cin >> roots[i];
	}
	
	get_coeffs_3(roots);*/
	
	for(i=m;i;i--) cin >> k[i-1];
	
	/*for(i=0;i<m-2;i++) {
		cin >> roots[i];
	}
	
	get_coeffs_2(roots);*/
	
	cout.precision(10);
	cerr.precision(30);
	
	print_coeffs(k,m);
	derivative();
	
	
	if(k[3]==0) {
		//bx^2+cx+d
		if(k[2]==0) {
			cerr << "linear" << endl;
			//cx+d
			if(k[1]!=0) {
				rf[rf_c++]=-k[0]/k[1];
			}
			//else nothing
		}
		else {
			cerr << "parabola" << endl;
			long double D=k[1]*k[1]-4*k[0]*k[2];
			//|D**0.5/a|<eps
			if(D>=0) {
				cerr << "squared distance between roots: " <<
					abs((k[1]*k[1])/(k[2]*k[2])-4*(k[0]/k[2])) << endl;
				if(abs((k[1]*k[1])/(k[2]*k[2])-4*(k[0]/k[2]))<power(eps,2)) {
					cerr << "one root" << endl;
					rf[rf_c++]=-k[1]/(2*k[2]);
				}
				else {
					cerr << "two roots" << endl;
					if(k[2]>0) {
						rf[rf_c++]=(-k[1]-sqrt(D))/(2*k[2]);
						rf[rf_c++]=(-k[1]+sqrt(D))/(2*k[2]);
					}
					else {
						rf[rf_c++]=(-k[1]+sqrt(D))/(2*k[2]);
						rf[rf_c++]=(-k[1]-sqrt(D))/(2*k[2]);
					}
				}
			}
			else cerr << "no roots" << endl;
		}
	}
	else {
		cerr << "cubic" << endl;
		long double D=d[1]*d[1]-4*d[0]*d[2];
		if(D>=0) {
			cerr << "squared distance between derivative roots: " <<
				abs((d[1]*d[1])/(d[2]*d[2])-4*(d[0]/d[2])) << endl;
			if(abs((d[1]*d[1])/(d[2]*d[2])-4*(d[0]/d[2]))<power(eps,2)) {
				find(k,m,-interval,interval);
			}
			else {
				long double r1=(-d[1]-sqrt(D))/(2*d[2]),
					r2=(-d[1]+sqrt(D))/(2*d[2]),t;
				
				if(r1>r2) {
					t=r1;
					r1=r2;
					r2=t;
				}
				
				cerr << "two derivative roots: " << r1 << ", " << r2 << endl;
				
				find(k,m,-interval,r1);
				find(k,m,r1,r2);
				find(k,m,r2,interval);
			}
		}
		else  {
			cerr << "no derivative roots" << endl;
			find(k,m,-interval,interval);
		}
	}
	
	print_roots();
}


void derivative() {
	unsigned int i;
	for(i=1;i<m;i++) d[i-1]=k[i]*i;
}

void get_coeffs_3(long double* r) {
	//(x-a)(x-b)(x-c)
	//x^3-(a+b+c)x^2+x(ab+bc+ac)-abc	

	k[3]=1.0;
	
	k[0]=-1.0;
	k[2]=0;
	
	unsigned int i;
	for(i=0;i<(m-1);i++) {
		k[0]*=r[i];
		k[2]-=r[i];
	}
	
	k[1]=r[0]*r[1]+r[1]*r[2]+r[0]*r[2];
}

void get_coeffs_2(long double* r) {
	//(x-a)(x-b)
	//x^2-(a+b)x+ab
	
	k[3]=0;
	k[2]=1.0;
	k[1]=-1.0*(r[0]+r[1]);
	k[0]=r[0]*r[1];
}

long double abs(long double a) {
	return(a<0?-a:a);
}


void print_roots() {
	unsigned int i,si;
	
	for(i=0;i<rf_c;i++) {
		for(si=0;si<i;si++) {
			if(abs(rf[i]-rf[si])<=eps) {
				si=rf_c;
				break;
			}
		}
		if(si!=rf_c) {
			if(abs(rf[i])<=eps) cout << "0";
			else cout << rf[i];
			cout << " ";
		}
		//cout << "root #" << i+1 << ": " << rf[i] << endl;
	}
	cout << endl;
}


void print_coeffs(long double* k,unsigned int m) {
	unsigned int i;
	
	cerr << "coeffs:" << endl;
	
	for(i=m;i;i--) {
		if(k[i-1]) {
			if(k[i-1]!=1||i==1)
				cerr << k[i-1];
			if(i!=1) {
				if(k[i-1]!=1) cerr << "*";
				cerr << "x";
			}
			if(i>2) cerr << "^" << i-1;
			cerr << endl;
		}
	}
	
	cerr << endl;
}

void find(long double* k,unsigned int k_c,long double l,long double r) {
	long double test;
	unsigned int i;
	for(i=0;i<m-1;i++) {
		if(roots[i]>l&&roots[i]<r) {
			test=roots[i];
			break;
		}
	}
	
	
	
	cerr << "find() called: l=" << l << " (" << sgn(k,k_c,l)  << ") r=" << r << " (" << sgn(k,k_c,r) << ")" << endl;
	
	if(sgn(k,k_c,l)*sgn(k,k_c,r)>0) {
		cerr << "error!" << endl;
		return;
	}
	long double m;
	
	if(sgn(k,k_c,l)==0) {
		rf[rf_c++]=l;
		return;
	}
	if(sgn(k,k_c,r)==0) {
		rf[rf_c++]=r;
		return;
	}
	
	while(r-l>eps/2) {
		m=(l+r)/2;
		
		cerr << "l=" << l << " (" << sgn(k,k_c,l) << ")"
			<< " m=" << m << " (" << sgn(k,k_c,m) << ")"
			<< " r=" << r << " (" << sgn(k,k_c,r) << ")" << ": ";
		
		if(sgn(k,k_c,l)*sgn(k,k_c,m)<0) {
			cerr << "<=";
			r=m;
		}
		else {
			cerr << "=>";
			l=m;
		}
		
		if(l>test||r<test) cerr << " error " << "(" << test << ")";
		
		cerr << endl;
		
		if(sgn(k,k_c,m)==0) {
			rf[rf_c++]=m;
			return;
		}
	}
	
	rf[rf_c++]=(l+r)/2;
}

void psort_abs(long double* k,unsigned int m) {
	unsigned int i,si;
	long double t;
	for(i=0;i<m;i++) {
		for(si=0;si<(m-i-1);si++) {
			if(abs(k[si])<abs(k[si+1])) {
				t=k[si];
				k[si]=k[si+1];
				k[si+1]=t;
			}
		}
	}
}

short int sgn(long double* k,unsigned int m,long double x) {
	long double r=0;
	unsigned int i;
	long double* arr=new long double[m];
	for(i=0;i<m;i++) arr[i]=power(x,i)*k[i];
	psort_abs(arr,m);
	//for(i=0;i<m;i++) r+=arr[i];
	r=(arr[0]+arr[1])+(arr[2]+arr[3]);
	if(r==0) return(0);
	else if(r>0) return(1);
	else return(-1);
	/*long double sum1=0,sum2=0,sum=0;
	unsigned int i;
	
	for(i=0;i<m;i++) {
		sum+=abs((long double)(power(x,i)*k[i]));
	}
	sum/=m;
	
	long double t;
	for(i=0;i<m;i++) {
		t=power(x,i)*k[i];
		if(abs(t)>sum) sum2+=t;
		else sum1+=t;
	}
	
	if(sum1==0) {
		if(sum2>0) return(1);
		else if(sum2<0) return(-1);
		return(0);
	}
	else if(sum2==0) {
		if(sum1>0) return(1);
		else if(sum1<0) return(-1);
		return(0);
	}
	else {
		if(sum1>0&&sum2>0) return(1);
		else if(sum1<0&&sum2<0) return(-1);
		else if(sum1>0&&sum2<0) {
			if(sum1>-sum2) {
				return(1);
			}
			else if(sum1<-sum2) return(-1);
			else if(sum1==-sum2) return(0);
		}
		else if(sum1<0&&sum2>0) {
			if(sum2>-sum1) {
				return(1);
			}
			else if(sum2<-sum1) return(-1);
			else if(sum2==-sum1) return(0);
		}
	}*/
}


long double power(long double a,unsigned int b) {
	unsigned int i;
	long double r=1;
	for(i=0;i<b;i++) r*=a;
	return(r);
}

