 function degriserChamps () 
{  
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#donne2').selectmenu('enable');
    $('#donne3').selectmenu('enable');
    $('#donne4').selectmenu('enable');
    $('#donne5').textinput('enable');
    $('#donne6').textinput('enable');   
    $('#donne7').selectmenu('enable');
    $('#donne8').textinput('enable');
    $('#donne9').textinput('enable');
    $('#donne10').textinput('enable');
    $('#donne11').prop('disabled', false);  
    $('#donne11').button('refresh');
    $('#donne12').textinput('disable');

    $('#geo').prop('disabled',false);
    $('#geo').button('refresh');

    $('#pic').attr('class', 'ui-btn ui-corner-all ui-btn-inline');
};

function griserChamps () 
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
  
    $('#donne2').selectmenu('disable');   
    $('#donne3').selectmenu('disable');  
    $('#donne4').selectmenu('disable');  
    $('#donne5').textinput('disable');  
    $('#donne6').textinput('disable');  
    $('#donne7').selectmenu('disable');  
    $('#donne8').textinput('disable');  
    $('#donne9').textinput('disable');  
    $('#donne10').textinput('disable');  

    $('#donne11').prop('disabled', true);  
    $('#donne11').button('refresh');  
    $('#donne12').textinput('disable');
    
    $('#geo').prop('disabled', true); 
    $('#geo').button('refresh'); 

     $('#pic').attr('class', 'ui-btn ui-corner-all ui-btn-inline ui-disabled');
    
    $('#save').prop('disabled', true);
    $('#save').button('refresh');
};

function modifierBtnNouveau()
{
    if ($('#nouveau').val() == 'Nouveau')
    {
        //Degrise tout quand clic sur nouveau   
        $('#nouveau').prop('value', 'Annuler');
        $('#nouveau').button('refresh');
        return;
    }
    else 
    {
        $('#nouveau').prop('value', 'Nouveau');
        $('#nouveau').button('refresh');
        return;
    }
};

function modifierBtnModifier()
{
    if ($('#modifier').val() == 'Modifier')
    {
        //Degrise tout quand clic sur nouveau   
        $('#modifier').prop('value', 'Annuler');
        $('#modifier').button('refresh');
        return;
    }
    else 
    {
        $('#modifier').prop('value', 'Modifier');
        $('#modifier').button('refresh');
        return;
    }
};

function degriserTableau()
{
    $('#tab2').attr('class', ' ui-listview');
};

function griserTableau()
{
    $('#tab2').attr('class', 'ui-disabled ui-listview');
};

function degriserBtnSuppModif()
{
    $('#supprimer').prop('disabled', false);  
    $('#supprimer').button('refresh');
    $('#modifier').prop('disabled', false);  
    $('#modifier').button('refresh');
};

function griserBtnSuppModif()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#modifier').prop('disabled', true);  
    $('#modifier').button('refresh');
};

function griserBtnSuppSave()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#nouveau').prop('disabled', true);  
    $('#nouveau').button('refresh');
};

function griserBtnSuppSave()
{
    $('#supprimer').prop('disabled', true);  
    $('#supprimer').button('refresh');
    $('#nouveau').prop('disabled', true);  
    $('#nouveau').button('refresh');
};

function remplirChamps()
{
    var value = "";
    $(this).find('td').each(function(i)
        {
         $('#donne'+i).val($(this).html());      
        });
    
    $('#input1').val(value);
};

function modeRevue()
{
    $('#ChangMod').val('Mode Enregistrement');
    $('.ui-content').css("background-color", "#9D5207");    
    
};

function modeEnregistrement()
{
    $('#ChangMod').val('Mode Revue');
    $('.ui-content').css("background-color", "#610b21"); 
};