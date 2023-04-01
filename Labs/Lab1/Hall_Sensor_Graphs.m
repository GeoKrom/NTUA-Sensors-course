%% Sensor Lab 1: Hall Sensor

clc
clear
close all

% Constants
m0=4*pi*10^(-7);
N=189;
L=38e-3;
r=22e-3;
k=N/(2*sqrt(L^2/4+r^2));

% Measurements
Vout_plus=[2.4,2.4,2.41,2.42,2.42,2.42,2.43,2.43,2.43,2.44,2.44,2.44,2.45];
Vout_minus=[2.38,2.38,2.36,2.36,2.35,2.34,2.32,2.32,2.31,2.31,2.30,2.29,2.29];

% Inputs
I=0.2:0.2:2.6;
H=k.*I;
B=m0.*H; %Measured in Tesla

B_total =[-B(end:-1:1),B]';
V_total =[Vout_minus(end:-1:1),Vout_plus]';
b = regress(V_total,[ones(size(B_total)),B_total]);
V_OLS = [ones(size(B_total)),B_total]*b;
a=(4-2.5)/0.1; %1000Gauss=0.1T
V_Datasheet=2.5+a*B_total;
%% Figures

figure(1)
clf
plot(B_total,V_total,'bo') %Reasurement
hold on
plot(B_total,V_OLS,'k--') %OLS result
xlabel('B [Tesla]')
ylabel('V_{out} [V]')
grid minor
title('Hall Sensor Calibration')

figure(2)
clf
plot(B_total,V_total,'bo') %Reasurement
hold on
plot(B_total,V_OLS,'k--') %OLS result
plot(B_total,V_Datasheet,'r--') %Datasheet result
xlabel('B [Tesla]')
ylabel('V_{out} [V]')
grid minor
title('Datasheet Curve vs Measured Curve')
legend('Measurements','Calibration Curve','Datasheet Curve')