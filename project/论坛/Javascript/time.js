 dayObj=new Date();

monthStr=dayObj.getMonth()+1;

if(dayObj.getYear()<99)

year2000=2000+dayObj.getYear();  

else year2000=dayObj.getYear();

    document.write("������"+year2000+"��"+monthStr+"��"+dayObj.getDate()+"��"+" ");  

if(dayObj.getDay()==1)

document.write("����һ");

if(dayObj.getDay()==2)

document.write("���ڶ�");  

if(dayObj.getDay()==3)

document.write("������");

    if(dayObj.getDay()==4)

document.write("������");

if(dayObj.getDay()==5)

document.write("������");

if(dayObj.getDay()==6)

document.write("������");

if(dayObj.getDay()==0)

document.write("������");