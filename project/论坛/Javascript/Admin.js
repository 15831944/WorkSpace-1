 function insertUser()
  {
	 word.innerHTML="����û�";
	 see.innerHTML="<form onSubmit='/cgi-bin/AddUser.cgi' action='/cgi-bin/AddUser.cgi' method=get>������û�<hr>�û���<br><input name='username' type='text' id='username' size='25' /><br>�� ��<br><input name='password' type='password' id='password' size='25' /><br>Email<br><input name='email' type='text' id='email' size='25' /><br>�û���<br><select name='select' id='select'><option value = '0' selected>������·</option></select><br><br><input type='submit' value='��    ��'/></form>";
	 //see.innerHTML="";
  }

  function ForbidUser()
  {
	word.innerHTML="��ֹ�û�";
	see.innerHTML="<form onSubmit='/cgi-bin/ForbidUser.cgi' action='/cgi-bin/ForbidUser.cgi' method=get>��ֹ�û�<hr>��ֹ�û���<br><input name='username' type='text' id='username' size='25' /><hr><br>��ֹ����<br><input type='radio' name='type' id='radio' value='1'>����״̬<br><input type='radio' name='type' id='radio' value='2' checked>��ֹ����<br><input type='radio' name='type' id='radio' value='3'>��ֹ����<hr><br>ɾ�����û�������:<input type='radio' name='delete' id='radio2' value='1'>��<input type='radio' name='delete' id='radio2' value='0' checked>��<br><br><input type='submit' value='ִ��'/></form>";
  }