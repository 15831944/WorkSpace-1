function insertFormat()
		{
		   format.innerHTML ="���Ӱ��";
		   addFormat.innerHTML ="<form onSubmit='/cgi-bin/AddBlock.cgi' action='/cgi-bin/AddBlock.cgi' method=get>�����µİ��<hr>�������<br><input name='blockname' type='text' id='name' size='25'><hr>��Ӱ���<br><input type='radio' name='addmaster' id='radio3' value='1' checked>��<input type='radio' name='addmaster' id='radio3' value='0'>��<hr>�����û���<br><input name='mastername' type='text' id='formatName' size='25'><hr><input type='submit' id='button' value='  �ύ  '></form>";
		}
		function AdminFormat()
		{
		  format.innerHTML ="������";
		  addFormat.innerHTML ="<form onSubmit='/cgi-bin/AlterBlock.cgi' action='/cgi-bin/AlterBlock.cgi' method=get>������<input type='button' name='Update' id='Update' value='�޸�' onClick='AdminFormat()'><input type='button'  id='delete' value='ɾ��' onClick='DeleteFormat()'><hr>ԭ�������<br><input name='oldname' type='text' id='oldname' size='25'><hr>�޸ĺ�������<br><input name='newname' type='text' id='newname' size='25'><hr>��Ӱ���<br><input type='radio' name='addmaster' id='radio3' value='1' checked>��<input type='radio' name='addmaster' id='radio3' value='0'>��<hr>�����û���<br><input name='mastername' type='text' id='formatName' size='25'><hr><input type='submit' id='button' value='�޸İ��'></form>";
		}
		function DeleteFormat()
		{
		  addFormat.innerHTML ="<form onSubmit='/cgi-bin/DeleteBlock.cgi' action='/cgi-bin/DeleteBlock.cgi' method=get>������<input type='button' name='Update' id='Update' value='�޸�' onClick='AdminFormat()'><input type='button'  id='delete' value='ɾ��'><hr>�������<br><input name='blockname' type='text' id='name' size='25'><hr><input type='submit' id='button' value='ɾ�����'></form>";
		}