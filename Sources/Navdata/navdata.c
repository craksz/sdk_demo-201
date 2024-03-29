#include <ardrone_tool/Navdata/ardrone_navdata_client.h>

#include <Navdata/navdata.h>
#include <Gamepad/gamepad.h>
#include "UI/gui.h"
#include <stdio.h>


#define upTo 0


static char theString[500];
static int theCounter=0;

/*inline C_RESULT demo_navdata_client_init( void* data )
{
  return C_OK;
}

inline C_RESULT demo_navdata_client_process( const navdata_unpacked_t* const navdata )
{
	const navdata_demo_t*nd = &navdata->navdata_demo;	
	
  vControl *buffControl;
	if (theCounter>=upTo){
  gdk_threads_enter();
  gui_t *gui = get_gui();
	if (gui){
		gui->batteryLevel=nd->vbat_flying_percentage;
		if(nd->ctrl_state!=0)
			sprintf(theString,"Status: OK! \nBattery:\t%imV\nAltitude\t%i\n",gui->batteryLevel,nd->altitude);
		else
			sprintf(theString,"Status: EMERGENCY! \nBattery:\t%i\nAltitude\t%i\n",gui->batteryLevel,nd->altitude);
			
		gtk_label_set_text((GtkLabel*)gui->labelL,theString);
		sprintf(theString,
				"\n\nOrientation:\n\t\t\t[Theta]%4.1f\n\t\t\t[Phi]%4.1f\n\t\t\t[Psi] %4.1f\nSpeed:\n\t\t\t[vX]%4.3f\n\t\t\t[vY] %4.3f\n\t\t\t[vZPsi] %4.3f\n",
				nd->theta/100.0,nd->phi/100.0,nd->psi/100.0,nd->vx,nd->vy,nd->vz);
		gtk_label_set_text((GtkLabel*)gui->labelR,theString);
		buffControl=getSomeData(1);
		sprintf(theString,
				"\n\nControl %s:\n\t\t\t[Ref]%4.1f\n\t\t\t[Inicial]%4.1f\n\t\t\t[Vout]%1.5f",
				"x",buffControl->ref,buffControl->vin, buffControl->vout);
		gtk_label_set_text((GtkLabel*)gui->labelX,theString);
		
		buffControl=getSomeData(2);
		sprintf(theString,
				"\n\nControl %s:\n\t\t\t[Ref]%4.1f\n\t\t\t[Inicial]%4.1f\n\t\t\t[Vout]%1.5f",
				"y",buffControl->ref,buffControl->vin, buffControl->vout);
		gtk_label_set_text((GtkLabel*)gui->labelY,theString);
		
		buffControl=getSomeData(3);
		sprintf(theString,
				"\n\nControl %s:\n\t\t\t[Ref]%4.1f\n\t\t\t[Inicial]%4.1f\n\t\t\t[Vout]%1.5f",
				"yaw",buffControl->ref,buffControl->vin, buffControl->vout);
		gtk_label_set_text((GtkLabel*)gui->labelW,theString);
		
		buffControl=getSomeData(4);
		sprintf(theString,
				"\n\nControl %s:\n\t\t\t[Ref]%4.1f\n\t\t\t[Inicial]%4.1f\n\t\t\t[Vout]%3.5f",
				"z",buffControl->ref,buffControl->vin, buffControl->vout);
		gtk_label_set_text((GtkLabel*)gui->labelZ,theString);
		
	}
  gdk_threads_leave();
  theCounter=0;
  }
  else theCounter++;
  buffControl=getSomeData(4);
  //printf("convive! %0.2f\n",chingao->h[1]);
  buffControl->vin=nd->altitude;
	//fuzzyControl(buffControl);
	//dispControl( chingao , 'Z' );

  return C_OK;
}

inline C_RESULT demo_navdata_client_release( void )
{
  return C_OK;
}
//*/

inline C_RESULT demo_navdata_client_init( void* data )
{
    someFunction();
  return C_OK;
}

inline C_RESULT demo_navdata_client_process( const navdata_unpacked_t* const navdata )
{
	const navdata_demo_t*nd = &navdata->navdata_demo;

	printf("=====================\nNavdata for flight demonstrations =====================\n\n");

	printf("Control state : %i\n",nd->ctrl_state);
	printf("Battery level : %i mV\n",nd->vbat_flying_percentage);
	printf("Orientation   : [Theta] %4.3f  [Phi] %4.3f  [Psi] %4.3f\n",nd->theta,nd->phi,nd->psi);
	printf("Altitude      : %i\n",nd->altitude);
	printf("Speed         : [vX] %4.3f  [vY] %4.3f  [vZPsi] %4.3f\n",nd->theta,nd->phi,nd->psi);

	printf("\033[8A");

  return C_OK;
}

inline C_RESULT demo_navdata_client_release( void )
{
  return C_OK;
}//*/

BEGIN_NAVDATA_HANDLER_TABLE
  NAVDATA_HANDLER_TABLE_ENTRY(demo_navdata_client_init, demo_navdata_client_process, demo_navdata_client_release, NULL)
END_NAVDATA_HANDLER_TABLE

