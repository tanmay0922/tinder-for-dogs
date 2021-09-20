#include<stdio.h>
/structure to store time information/
typedef struct{
int hour;
int mins;
} time;
/structure to store flight plans/
typedef struct{
int flightid;
time depart;//Departure time
time arrive;//Arrival time
} flightplan;
/*structure to store the flight time
for every flight/
typedef struct{
int flightid;
int ftime;
} flighttime;
/* Function to take input from
the users*/
int getdata(flightplan _fp[]){
int n,i;
printf("\nHow many data:");
scanf("%d",&n);
for(i=0; i<n; i++){
printf("\nFlight ID:");
scanf("%d",&_fp[i].flightid);
printf("\nDeparture Hour:");
scanf("%d",&_fp[i].depart.hour);
printf("\nDeparture Mins:");
scanf("%d",&_fp[i].depart.mins);
printf("\nArrival Hour:");
scanf("%d",&_fp[i].arrive.hour);
printf("\nArrival Mins:");
scanf("%d",&_fp[i].arrive.mins);
}
return n; }
/* Function to calculate flight time for all the flight plans*/
void calculate_time(flightplan _fp[], flighttime _ft[], int n){
int i;
for(i=0; i<n; i++){
_ft[i].flightid = _fp[i].flightid;
/* Convert differences in hours and mins to total
* minutes between the departure time and the
* arrival time */
_ft[i].ftime = (_fp[i].arrive.hour - _fp[i].depart.hour)*60
+ (_fp[i].arrive.mins - _fp[i].depart.mins);
}
}
/* Function to find the flight ID with maximum flight time */
int maxflight (flighttime _ft[], int n){
int maxid=-1, maxtime=-1;
int i;
for(i=0; i<n; i++){
if(_ft[i].ftime > maxtime){
maxtime = _ft[i].ftime;
maxid = _ft[i].flightid;
}}
return maxid;
}int main()
{flightplan fp[10];
flighttime ft[10];
int n;
n = getdata(fp);
calculate_time(fp, ft, n);
printf("\nFlight ID for maximum flight time is:%d",maxflight(ft,n));
return 0;
}