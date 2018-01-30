function debug(){
$.ajax({	
	type : 'GET',
	url : '/cgi-bin/datatest',
	dataType : 'json',
	data : 'donne1='+$('#donne1').val()+'&donne2='+$('#donne2').val()+
		'&donne3='+$('#donne3').val(),
	success : function (data) {			
			 alert(data.enregistrement[0].id);
	},
	error : function (result, status, erreur){
		alert(erreur);
	},
	});
}
