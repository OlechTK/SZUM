


x1=0;
y1=4;

x2=0;
y2=7;

x3=3;
y3=5;

xc=1;
yc=6;
zc=3;

xn=0;
yn=0;
zn=0;

kroki1=0;
kroki2=0;
kroki3=0;

wolny=0;

r=4;

     if(exist('s'))
        fclose(s);
        delete(s);
        clear s;
         end
    
    
    s = serial('COM5','BaudRate',57600)
    pause(1);
    fopen(s);
    

    
    

z1=zc+sqrt(r^2-(y1-yc)^2-(x1-xc)^2);
z2=zc+sqrt(r^2-(y2-yc)^2-(x2-xc)^2);
z3=zc+sqrt(r^2-(y3-yc)^2-(x3-xc)^2);

cd1=line([0 0], [4 4], [0 8])
cd2=line([0 0], [7 7], [0 8])
cd3=line([3 3], [5 5], [0 8])

arm1=line([x1 xc], [y1 yc], [z1 zc])
arm2=line([x2 xc], [y2 yc], [z2 zc])
arm3=line([x3 xc], [y3 yc], [z3 zc])
view(-42,-4)

clear z1p

    str = sprintf('x %d y %d z %d\n',-100, -100, -100);
    fprintf(s, str);
    pause(8);

for t=0:0.1:20
    

    
    xc=sin(t)+1.5;
    yc=cos(t)+5.5;
    zc=3-t/4;
    
    
    z1=zc+sqrt(r^2-(y1-yc)^2-(x1-xc)^2);
    z2=zc+sqrt(r^2-(y2-yc)^2-(x2-xc)^2);
    z3=zc+sqrt(r^2-(y3-yc)^2-(x3-xc)^2);
    
    set(arm1, 'XData', [x1 xc], 'YData', [y1 yc], 'zdata', [z1 zc]);
    set(arm2, 'XData', [x2 xc], 'YData', [y2 yc], 'zdata', [z2 zc]);
    set(arm3, 'XData', [x3 xc], 'YData', [y3 yc], 'zdata', [z3 zc]);
    

    
    if (exist('z1p'))
              
    kroki1=(z1p-z1)*5000;
    kroki2=(z2p-z2)*5000;
    kroki3=(z3p-z3)*5000;
    
    kroki1=round(kroki1);
    kroki2=round(kroki2);
    kroki3=round(kroki3);
    
    end
   
    z1p=z1;
    z2p=z2;
    z3p=z3;
    
    text=['x ' num2str(kroki1) ' y ' num2str(kroki2) ' z ' num2str(kroki3) '\n'];
    
    
    pause(1.5);
    fprintf(s, text);
    
    
end

fclose(s);
delete(s);
clear s;
    