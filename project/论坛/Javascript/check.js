 function checkTheForm()
  {
    if(document.leavewordform.title.value==""&&document.leavewordform.content.value=="")
	{
	  alert("����ͻ��ⲻ��Ϊ�գ�");
     }   
  else if(document.leavewordform.title.value=="")
	{
	  alert("����ͻ��ⲻ��Ϊ�գ�"); 
	  }
  else if(document.leavewordform.content.value=="")
	  {
	    alert("�������ݲ���Ϊ�գ�"); 
	 }
	else
	 {
	   document.leavewordform.submit(); 
	   }
 }
  function checkForm()
  {
      if(document.leavewordform.content.value=="")
	  {
	    alert("�������ݲ���Ϊ�գ�"); 
	 }
	else
	 {
	   document.leavewordform.submit(); 
	   }
 }