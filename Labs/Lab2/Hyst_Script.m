%% Sensor's Lab 2: Hysterisis Loop

clc
clear
close all

%% Signal Processing and Current Calculation
Table = readtable('Hyst_Loop.xlsx','PreserveVariableNames',true);
t = Table.t;
Vout = Table.Vout;
Vin = Table.Vin;

T = 0.001; % Period
R = 100;
% m_r=10000;
m_r = 1; %TEST
m_0 = 4*pi*10^(-7);
N = 1100;
Length = 0.07;
D = 10^(-3);
L = (m_r*m_0*N^2*pi*(D/2)^2)/Length;

w = 2*pi/T;
Z = sqrt(R^2+(w*L)^2);
phi = atan((2*pi/T)*L/R);
t_phi = phi/w;
%I=V(s)/Z*exp(-jphi)
%Iin=[Vin(t>=(t(end)-t_phi));Vin(t<(t(end)-t_phi))]/Z;
Iin = Vin/R;
figure(1);
clf;
plot(t,Iin*10);
hold on;
plot(t,Vout);
grid on;
xlabel('t [s]','interpreter','latex');
ylabel('$I [10^{-1} A], V [V]$', 'Interpreter','latex');
legend('I_{in}','V_{out}');
title('Fluxgate Sensor Signal Output', 'Interpreter','latex');

%% Vout Integral Calculation
s=tf('s');
integral_Vout = lsim(1/s,Vout,t);

figure(2);
clf;
plot(t,integral_Vout);
grid on;
xlabel('t [s]','interpreter','latex');
ylabel('$\int{V_{out}}$','interpreter','latex');
title('$\int{V_{out}}$ as a function of time',...
    'interpreter','latex');

integral_Vout = lsim(1/s,Vout-mean(Vout),t);

figure(3);
clf;
plot(t,integral_Vout);
grid on;
xlabel('t [s]','interpreter','latex');
ylabel('$\int{(V_{out}-\bar{V}_{out})}$','interpreter','latex');
title('$\int{(V_{out}-\bar{V}_{out})}$ as a function of time',...
    'interpreter','latex');

%% Hysterisis Loop
figure(4);
clf;
plot(Iin,integral_Vout);
grid on;
xlabel('$I_{in} [A]$','interpreter','latex');
ylabel('$\int{(V_{out}-\bar{V}_{out})}$','interpreter','latex');
title('Hysterisis Loop of Fluxgate', 'Interpreter','latex');