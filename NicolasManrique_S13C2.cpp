#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

double ts( double dt, double dx, double dy, double nu, double t021, double t011, double t001, double t012, double t010 );


int main () {

    double dx=0.01;
    double dy=0.01;
    double nu = 0.0001;
    int n=100;
    double espacio0[n][n];
    double espacio1[n][n];
    double dt=0.01;
    double dt1;
    double dt2;
    dt1=(dx*dx)/(2*nu);
    dt2=(dy*dy)/(2*nu);

/*    if(dt1<dt2){
        dt=dt1;
    }
    else{
        dt=dt2;
    }*/


    int rep = 250000;
    
    


    for(int i=0; i<n ; i++){
        double posx;
        posx = i * dx;
        for(int j=0; j<n ; j++){
            double posy;
            posy = j * dy;
            if(posx>=0.1 && posx<=0.3 && posy>=0.4 && posy<=0.6 ){
                espacio0[i][j]=100;
                espacio1[i][j]=100;
            }
            else{
                espacio0[i][j]=50;
                espacio1[i][j]=50;
            }
            cout<< espacio0[i][j] <<" ";
        }
    }

    cout<<"\n";

    for(int k=0; k<rep ; k++){
        for(int i=1; i<n-1 ; i++){
            for(int j=1; j<n-1 ; j++){

                espacio1[i][j]=ts( dt, dx, dy, nu, espacio0[i+1][j], espacio0[i][j], espacio0[i-1][j], espacio0[i][j+1], espacio0[i][j-1] );

            }
        }
        if(k%(rep/5)==0){
            for(int i=0; i<n ; i++){
                for(int j=0; j<n ; j++){
                    espacio0[i][j]=espacio1[i][j];
                    cout<< espacio0[i][j] <<" ";
                }
            }
            cout << "\n";
        }
        else{
            for(int i=0; i<n ; i++){
                for(int j=0; j<n ; j++){
                    espacio0[i][j]=espacio1[i][j];
                }
            }
        }
    }

return 0;

}

double ts( double dt, double dx, double dy, double nu, double t021, double t011, double t001, double t012, double t010 ){
    
    double cx=nu*dt/(dx*dx);
    double cy=nu*dt/(dy*dy);

    double t211;
    t211=(cx*(t021-2*t011+t001))+(cy*(t012-2*t011+t010))+t011;
    return t211;

}


