function Task1_45799
xlabel('x') 
ylabel('y') 

drawCauchyTask();
Picard();
end
function drawCauchyTask()
xStart =1;
xStop=10;
yStart=-10;
yStop=10;

axis([xStart,xStop,yStart,yStop]);

hold on;
grid on;

y=dsolve('x*Dy=(-2)*y','y(2)=1','x');
x=xStart:1/1000:xStop;

plot(x,eval(y),'b');
y
end

function Picard
xmin=1;
xmax=10;
x0=2;
y0=1;

N=15;

x=x0:(xmin-x0)/100:xmin;
xx=x0:(xmax-x0)/100:xmax;

y_0=y0*ones(1,length(x));
yy_0=y0*ones(1,length(xx));

z=y_0;
zz=yy_0;

for k=1:N %Iterate

y_k=y0+cumtrapz(x,f(x,z));
yy_k=y0+cumtrapz(xx,f(xx,zz));

plot(x,z,'g',xx,zz,'g');

z=y_k;
zz=yy_k;
end
function z = f(x,y)
z=((-2)*y)./x;
end
legend('Real solution','1st iteration','2nd iteration','3th iteration','4th iteration','5th iteration', 'Location', 'SouthWest');
end