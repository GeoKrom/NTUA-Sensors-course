%% Sensor Lab 2: Flux Gate Sensor

clc
clear
close all

% Frequencies used
f=[1000,5000];
%% First Experiment
% Measurements
Vdc=(2.0:-0.5:-2.0)';
Delta_t=[-342,-236,-156,-88,-20,42,110,180,262;
        -66,-50,-33,-17,-4,9,22,37,55]';

Delta_t_OLS =zeros(size(Delta_t));
for i=1:length(f)
    
    b = regress(Delta_t(:,i),[ones(size(Vdc)),Vdc]);
    Delta_t_OLS(:,i) = [ones(size(Vdc)),Vdc]*b;
    
end

%% Figure for the 1st Experiment
figure(1)
clf
hold on
grid minor

for i=1:length(f)
plot(Vdc,Delta_t(:,i),'o') %Reasurement
plot(Vdc,Delta_t_OLS(:,i),'--') %OLS result
xlabel('$V_{dc}$ [V]','interpreter','latex')
ylabel('$\Delta t$ [$\mu sec$]','interpreter','latex')
end
title('Flux Sensor: Measured Curve for 1 kHz and 5 kHz',...
    'interpreter','latex')
legend('Measurements f=1 kHz','OLS Curve f=1 kHz','Measurements f=5 kHz',...
    'OLS Curve f=5 kHz')
%% Second Experiment
% Measurements
x=(0:5:50)';
V_pp=[1.85,1.75,1.65,1.535,1.355,1.225,1.145,0.915,0.730,0.515,0.3;
        4.3,4.05,3.86,3.62,3.34,3.06,2.77,2.41,1.97,1.53,0.84]';

Vpp_OLS =zeros(size(V_pp));
for i=1:length(f)
    
    b = regress(V_pp(:,i),[ones(size(x)),x]);
    Vpp_OLS(:,i) = [ones(size(x)),x]*b;
    
end

%% Figure for the 2nd Experiment
figure(2)
clf
hold on
grid minor

for i=1:length(f)
    plot(x,V_pp(:,i),'o') %Reasurement
    plot(x,Vpp_OLS(:,i),'--') %OLS result
    xlabel('$x$ [mm]','interpreter','latex')
    ylabel('$V_{pp}$ [V]','interpreter','latex')
end
title('Displacement Sensor: Measured Curve for 1 kHz and 5 kHz',...
    'interpreter','latex')
legend('Measurements f=1 kHz','OLS Curve f=1 kHz','Measurements f=5 kHz',...
    'OLS Curve f=5 kHz')