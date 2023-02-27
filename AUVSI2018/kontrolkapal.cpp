#include "kontrolkapal.h"

KontrolKapal::KontrolKapal(QObject *parent)
	: QObject(parent)
{
	
}

KontrolKapal::~KontrolKapal()
{

}

void KontrolKapal::retry_kontrol()
{
	penanda_misi3 = 0;
	counter_misi3 = 0;
	penanda_docking_misi3 = 0;
	status_misi3 = 0;
	timer_misi3 = false;
	timer_misi5 = false;
	timeout_misi = false;
}

int SRF1 = 0;
int SRF2 = 0;
int SRF3 = 0;
int SRF4 = 0;
int SRF5 = 0;
int SRF_kiri;
int SRF_kanan;
bool status_waypoint = false;

void KontrolKapal::mulai_misi()
{
	status_waypoint = true;
	connect(timer_mundur, SIGNAL(timeout()), this, SLOT(tidak_mundur()));
	connect(timer_rotate_misi3, SIGNAL(timeout()), this, SLOT(stop_rotate()));
	connect(timer_mission, SIGNAL(timeout()), this, SLOT(next_mission()));
}

void KontrolKapal::stop_misi()
{
	status_waypoint = false;
}

void KontrolKapal::terima_SRF(int srf1, int srf2, int srf3, int srf4, int srf5)
{
	SRF1 = srf1;
	SRF2 = srf2;
	SRF3 = srf3;
	SRF4 = srf4;
	SRF5 = srf5;
	SRF_kiri = SRF1 + SRF2;
	SRF_kanan = SRF3 + SRF4;
} 

int frequency_kontrol = 0;
int amplitude_kontrol = 0;
void KontrolKapal::terima_Hydro(int freq, int amp)
{
	frequency_kontrol = freq;
	amplitude_kontrol = amp;
}

int ambil_gambar_misi3 = 0;
int drone_mendarat = 0;
void KontrolKapal::terima_Drone(int gambar, int mendarat)
{
	
}

int trim = 0;
void KontrolKapal::trim_motor(int variable)
{
	trim = variable;
}

int timeout_misi3 = 200000;
int timeout_misi5 = 100000;

void KontrolKapal::ubah_timeout_misi3(int timeout)
{
	timeout_misi3 = timeout*1000; // ms to second
	qDebug() << "timeout_misi3 changed";
}

void KontrolKapal::ubah_timeout_misi5(int timeout)
{
	timeout_misi5 = timeout*1000; // ms to second
	qDebug() << "timeout_misi5 changed";
}

int servo_imgproc = 1500;
int servo_imgproc2 = 1500;
int speed_imgproc = 1500;

void KontrolKapal::terima_pidout_imgproc(float serv)
{
	servo_imgproc = (int)serv;
}

void KontrolKapal::terima_pidout_imgproc2(int speed,float serv)
{
	speed_imgproc = speed;
	servo_imgproc2 = (int)serv;
}

int stop_misi1 = 7;
int stop_misi2 = 11;
int stop_misi3 = 15;
int stop_misi4 = 19;
int stop_misi5 = 23;
int stop_misi6 = 25;
int stop_return = 27;

int waypoint_misi1 = 6;
int waypoint_misi2 = 10;
int waypoint_misi3 = 14;
int waypoint_misi3_2 = 4;
int waypoint_misi4 = 18;
int waypoint_misi5 = 22;
int waypoint_misi6 = 24;
int waypoint_return = 26;

int speed_navigasi = 1750;
int speed_misi1 = 1800;
int speed_misi2 = 1850;
int speed_tengah_misi2 = 1800;
int speed_misi3 = 1650;
int speed_misi4 = 1650;
int speed_misi5 = 1700;
int speed_misi5_bawah = 1550;
int speed_misi6 = 1700;
int speed_misi3_atas = 1650;
int speed_return = 1900;

void KontrolKapal::change_stop_misi1(int variable)
{
	stop_misi1 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_misi2(int variable)
{
	stop_misi2 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_misi3(int variable)
{
	stop_misi3 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_misi4(int variable)
{
	stop_misi4 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_misi5(int variable)
{
	stop_misi5 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_misi6(int variable)
{
	stop_misi6 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_stop_return(int variable)
{
	stop_return = variable;
	qDebug() << "variablechanged";
}

void KontrolKapal::change_waypoint_misi1(int variable)
{
	waypoint_misi1 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi2(int variable)
{
	waypoint_misi2 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi3(int variable)
{
	waypoint_misi3 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi3_2(int variable)
{
	waypoint_misi3_2 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi4(int variable)
{
	waypoint_misi4 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi5(int variable)
{
	waypoint_misi5 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_misi6(int variable)
{
	waypoint_misi6 = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_waypoint_return(int variable)
{
	waypoint_return = variable;
	qDebug() << "variablechanged";
}
void KontrolKapal::change_speed_misi1(int variable)
{
	speed_misi1 = variable;
	qDebug() << "speedchanged1";
}
void KontrolKapal::change_speed_misi2(int variable)
{
	speed_misi2 = variable;
	qDebug() << "speedchanged2";
}
void KontrolKapal::change_speed_tengah_misi2(int variable)
{
	speed_tengah_misi2 = variable;
	qDebug() << "speedtengahchanged2";
}
void KontrolKapal::change_speed_misi3(int variable)
{
	speed_misi3 = variable;
	qDebug() << "speedchanged3";
}
void KontrolKapal::change_speed_misi4(int variable)
{
	speed_misi4 = variable;
	qDebug() << "speedchanged4";
}
void KontrolKapal::change_speed_misi5(int variable)
{
	speed_misi5 = variable;
	qDebug() << "speedchanged5";
}
void KontrolKapal::change_speed_misi5_bawah(int variable)
{
	speed_misi5_bawah = variable;
	qDebug() << "speedchanged5b";
}
void KontrolKapal::change_speed_misi6(int variable)
{
	speed_misi6 = variable;
	qDebug() << "speedchanged5";
}
void KontrolKapal::change_speed_misi3_atas(int variable)
{
	speed_misi3_atas = variable;
	qDebug() << "speedchanged3a";
}
void KontrolKapal::change_speed_return(int variable)
{
	speed_return = variable;
	qDebug() << "speedchanged6";
}
void KontrolKapal::change_speed_navigation(int variable)
{
	speed_navigasi = variable;
	qDebug() << "speedchanged0";
}

int setpoint_misi3;
void KontrolKapal::ambil_setpoint_misi3(int set)
{
	setpoint_misi3 = set;
	qDebug() << setpoint_misi3;
}
int setpoint_misi5 = 240;
void KontrolKapal::ambil_setpoint_misi5(int set)
{
	setpoint_misi5 = set;
	qDebug() << setpoint_misi5;
}
int sudut_misi3 = 90;
void KontrolKapal::ambil_sudut_misi3(int sudut)
{
	sudut_misi3 = sudut;
	qDebug() << "sudut misi 3 changed";
}
int frequency_misi3 = 55000;
void KontrolKapal::change_frequency_misi3(int freq)
{
	frequency_misi3 = freq;
	qDebug() << "frequency misi 3 changed";
}
int threshold_pinger = 40;
void KontrolKapal::change_threshold_pinger(int thres)
{
	threshold_pinger = thres;
	qDebug() << "threshold pinger changed";
}
int max_pinger = 40;
void KontrolKapal::change_max_pinger(int max)
{
	max_pinger = max;
	qDebug() << "max pinger changed";
}


void KontrolKapal::tujuanWaypoint(double latt,double longi,int idx)
{
	latt_waypoint[idx] = latt;
	long_waypoint[idx] = longi;
}

void KontrolKapal::ambilDataKontrolGPS(double lat, double lon, float comp)
{
	latt_kontrol = (double)lat;
	long_kontrol = (double)lon;
	comp_kontrol = (double)comp;
}

float sudutCompass;
float sudutTujuan;
float errorSudut;
float errorSebelum = 0;


float error_misi3 = 0.0;
float error_misi3_sebelum = 0.0;
double jarak;

int speed_kiri = 1500;
int speed_kanan = 1500;
int speed_tengah = 1500;
int servo = 1500;
int servo_kiri;
int servo_kanan;
int trim_servo_kiri;
int trim_servo_kanan;

int servo_nav = 1500;
int index_plot_waypoint = 1;

double kontrol_navigasi_P = 7;
double kontrol_navigasi_I = 0.2;
double kontrol_navigasi_D = 2.9;

float P_misi3;
float I_misi3;
float D_misi3;


int docking_misi3 = 0;


float sudutTujuan_misi3;
int errorSudut_misi3;
int errorSudut_misi3_sebelum;
bool start_counter_misi3 = false;
bool maju = true;

int nilai_counter_misi3 = 0;

void KontrolKapal::trim_serv_kiri(int serv)
{
	trim_servo_kiri = serv;
}

void KontrolKapal::trim_serv_kanan(int serv)
{
	trim_servo_kanan = serv;
}

void KontrolKapal::ubah_PID(double P, double I, double D)
{
	kontrol_navigasi_P = P;
	kontrol_navigasi_I = I;
	kontrol_navigasi_D = D;

	qDebug() << kontrol_navigasi_D << kontrol_navigasi_I << kontrol_navigasi_P;
}

void KontrolKapal::ubah_PID_misi3(float P, float I, float D)
{
	P_misi3 = P;
	I_misi3 = I;
	D_misi3 = D;

	qDebug() << P_misi3 << I_misi3 << D_misi3 << endl;
}

void KontrolKapal::terima_index(int idx)
{
	index_plot_waypoint = idx;
}


void KontrolKapal::kontrol_waypoint()
{
	if (latt_waypoint[index_plot_waypoint] != NULLPOINT && long_waypoint[index_plot_waypoint] != NULLPOINT)
	{
		jarak = (sqrt(pow(latt_waypoint[index_plot_waypoint] - latt_kontrol, 2) + pow(long_waypoint[index_plot_waypoint] - long_kontrol, 2)))*110574.6108;

		if (index_plot_waypoint-1 == waypoint_misi1)
		{
			mission_state = 1;
			emit ubah_state_imgproc(1);
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint-1 == waypoint_misi2)
		{
			mission_state = 2;
			emit ubah_state_imgproc(2);
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint-1 == waypoint_misi3)
		{
			mission_state = 3;
			emit ubah_state_imgproc(3);
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint-1 == waypoint_misi4)
		{
			mission_state = 4;
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint-1 == waypoint_misi5)
		{
			mission_state = 5;
			emit ubah_state_imgproc(5);
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint - 1 == waypoint_misi6)
		{
			mission_state = 6;
			emit ubah_state_imgproc(6);
			//emit mission_changed(mission_state);
		}
		else if (index_plot_waypoint-1 == waypoint_return)
		{
			mission_state = 7; // return to home
			//emit mission_changed(mission_state);
		}
		else if(index_plot_waypoint-1 == 0 || index_plot_waypoint-1 == stop_misi1 || index_plot_waypoint-1 == stop_misi2 || index_plot_waypoint-1 == stop_misi3 || index_plot_waypoint-1 == stop_misi4 || index_plot_waypoint-1 == stop_misi5 || index_plot_waypoint-1 == stop_return || index_plot_waypoint-1 == stop_misi6)
		{
			mission_state = 0;
		}	

		switch (mission_state)
		{
		case 0:
			speed_kiri = speed_navigasi;
			servo = kontrol_navigasi();

			if (SRF1 < 210 || SRF2 < 210 || SRF3 < 210 || SRF4 < 210)
			{
				if (SRF_kiri < SRF_kanan)
				{
					servo = 2100;
				}
				else if (SRF_kanan < SRF_kiri)
				{
					servo = 900;
				}
			}
			if (SRF2 < 45 || SRF3 < 45)
			{
				kontrol_mundur(2000);
			}
			break;
		case 1:
			emit change_servo_camera(1250, 1500); // (1450,1500)
			speed_kiri = speed_misi1;
			servo = servo_imgproc;
			if (servo == 0)
			{
				servo = kontrol_navigasi();
			}
			break;
		case 2:
			emit change_servo_camera(1100, 1500); //(1250,1500)
			speed_kiri = speed_misi2;
			servo = servo_imgproc;
			if (index_plot_waypoint == waypoint_misi2) //sebelumnya kondisis ini ngga ada
			{
				servo == 0;
			}
			if (servo == 0)
			{
				servo = kontrol_navigasi();
				 if (servo > 1750)
				{
					servo = 1500 - (servo - 1500);
				}
			}
			if (servo > 1900 && servo != 0)
			{
				servo = 1900;
			}
			else  if (servo < 1100 && servo != 0)
			{
				servo = 1100;
			}
			if (SRF1 < 140 || SRF2 < 140 || SRF3 < 140 || SRF4 < 140)
			{
				servo = 1750;
			}
			speed_tengah = speed_tengah_misi2;
			break;
		case 3:
			emit change_servo_camera(1500, 800); // (1800, 800)
			if (timer_misi3 == false)
			{
				timeout_misi = false;
				timer_mission->start(200000); // awalnya 360000
				timer_misi3 = true;
			}
			if (timeout_misi)
			{
				speed_kiri = speed_misi3_atas;
				servo = kontrol_navigasi();
				if (SRF1 < 210 || SRF2 < 210 || SRF3 < 210 || SRF4 < 210)
				{
					if (SRF_kiri < SRF_kanan)
					{
						servo = 2100;
					}
					else if (SRF_kanan < SRF_kiri)
					{
						servo = 900;
					}
				}
				if (SRF2 < 60 || SRF3 < 60)
				{
					kontrol_mundur(1000);
				}
			}
			else {
				switch (status_misi3)
				{
				case 0://kontrol waypoint
					servo = kontrol_navigasi();
					speed_kiri = speed_misi3_atas;
					if (index_plot_waypoint - 1 == waypoint_misi3_2)
					{
						status_misi3++;
					}
					break;
				case 1://find the first dock
					speed_kiri = speed_misi3 + 40;
					if (servo_imgproc == -2) // lihat merah
					{
						counter_misi3 = 0;
						start_counter_misi3 = true;
					}
					else if (servo_imgproc == -1) //lihat hijau
					{
						start_counter_misi3 = false;
					}
					if (penanda_misi3 > max_pinger)
					{
						status_misi3++;
						sudutTujuan_misi3 = comp_kontrol - sudut_misi3;
						nilai_counter_misi3 = counter_misi3;
					}
					if (start_counter_misi3)
					{
						counter_misi3++;
						speed_kiri = speed_misi3;
					}
					else
					{
						counter_misi3 = 0;
						penanda_misi3 = 0;
					}

					servo = kontrol_tembok(setpoint_misi3);

					if (frequency_kontrol > (frequency_misi3 - 10000) && frequency_kontrol < (frequency_misi3 + 10000) && amplitude_kontrol > threshold_pinger && start_counter_misi3 == true)
					{
						penanda_misi3++;
					}
					if (SRF5 <= 550 && SRF5 > 300)
					{
						servo = 1600;
					}
					else if (SRF5 > 550)
					{
						servo = 850;
						speed_kiri = speed_misi3_atas;
					}
					if (SRF1 < 130 || SRF2 < 200 || SRF3 < 200 || SRF4 < 200)
					{
						servo = 1850;
						speed_kiri = speed_misi3_atas;
					}
					break;
				case 2://Rotate

					speed_kiri = speed_misi3_atas;
					servo = 850;

					if ((comp_kontrol + 180) < (sudutTujuan_misi3 + 180))
					{
						status_misi3++;
					}
					break;
				case 3://Docking...

					if (penanda_docking_misi3 == 0)
					{
						timer_rotate_misi3->start(45000);
						penanda_docking_misi3 = 1;
						emit drone_terbang(1);
					}
					servo = 1500;
					speed_kiri = speed_misi3;
					break;
				case 4://Mundur
					kontrol_mundur(2200);
					sudutTujuan_misi3 = comp_kontrol + 90;
					status_misi3++;
					break;
				case 5://Rotate

					status_misi3++;
					break;
				case 6://Find next dock
					second_dock = 3;
					if (nilai_counter_misi3 < 550)
					{
						first_dock = 1;
					}
					else if (nilai_counter_misi3 >= 550 && nilai_counter_misi3 < 1000)
					{
						first_dock = 2;
					}
					else if (nilai_counter_misi3 >= 1000)
					{
						first_dock = 3;
					}
					if (penanda_docking_misi3 == 1)
					{
						penanda_docking_misi3 = 2;
						if (first_dock == second_dock)
						{
							status_misi3 = 8;
							penanda_docking_misi3 = 3;
							qDebug() << "diem ditempat";
						}
						else if (first_dock == 1 && second_dock == 2)
						{
							timer_rotate_misi3->start(3200);
							qDebug() << "1 ke 2";
							maju = true; //maju
						}
						else if (first_dock == 1 && second_dock == 3)
						{
							timer_rotate_misi3->start(6500);
							qDebug() << "1 ke 3";
							maju = true; //maju
						}
						else if (first_dock == 2 && second_dock == 1)
						{
							timer_rotate_misi3->start(4700);
							qDebug() << "2 ke 1";
							maju = false; //mundur
						}
						else if (first_dock == 2 && second_dock == 3)
						{
							timer_rotate_misi3->start(3200);
							speed_kiri = speed_misi3_atas;
							qDebug() << "2 ke 3";
							maju = true; //maju
						}
						else if (first_dock == 3 && second_dock == 1)
						{
							timer_rotate_misi3->start(8000);
							qDebug() << "3 ke 1";
							maju = false; //mundur
						}
						else if (first_dock == 3 && second_dock == 2)
						{
							timer_rotate_misi3->start(4700);
							qDebug() << "3 ke 2";
							maju = false; //mundur
						}
					}

					errorSudut_misi3 = sudutTujuan_misi3 - comp_kontrol;
					if (maju)
					{
						speed_kiri = 1700;
						servo = 1500 + ((kontrol_navigasi_P * errorSudut_misi3) + (kontrol_navigasi_D * (errorSudut_misi3 - errorSudut_misi3_sebelum)) + (kontrol_navigasi_I * (errorSudut_misi3 + errorSudut_misi3_sebelum)));					
					}
					else{
						speed_kiri = 1250;
						servo = 1500 - ((kontrol_navigasi_P * errorSudut_misi3) + (kontrol_navigasi_D * (errorSudut_misi3 - errorSudut_misi3_sebelum)) + (kontrol_navigasi_I * (errorSudut_misi3 + errorSudut_misi3_sebelum)));
					}
					errorSudut_misi3_sebelum = errorSudut_misi3;
					break;
				case 7://Rotate
					if (penanda_docking_misi3 == 2)
					{
						sudutTujuan_misi3 = comp_kontrol - sudut_misi3;
						penanda_docking_misi3++;
						emit drone_terbang(0);
					}
					speed_kiri = speed_misi3_atas;
					servo = 850;

					if ((comp_kontrol + 180) < (sudutTujuan_misi3 + 180))
					{
						status_misi3++;
					}
					break;
				case 8://Docking..
					if (penanda_docking_misi3 == 3)
					{
						timer_rotate_misi3->start(15000);
						penanda_docking_misi3++;
					}

					servo = 1500;
					speed_kiri = speed_misi3;
					break;
				case 9://Mundur
					kontrol_mundur(3000);
					status_misi3++;
					break;
				case 10://kontrol waypoint
					speed_kiri = speed_misi3_atas;

					servo = kontrol_navigasi();
					emit change_servo_camera(1450, 1500);
					if (SRF1 < 210 || SRF2 < 210 || SRF3 < 210 || SRF4 < 210)
					{
						if (SRF_kiri < SRF_kanan)
						{
							servo = 2100;
						}
						else if (SRF_kanan < SRF_kiri)
						{
							servo = 900;
						}
					}
					if (SRF2 < 45 || SRF3 < 45)
					{
						kontrol_mundur(2000);
					}
					break;
				}
			}
			break;
		case 4:
			speed_kiri = speed_misi4;
			servo = kontrol_navigasi();

			if (SRF1 < 110 || SRF2 < 130 || SRF3 < 130 || SRF4 < 110)
			{
				if (SRF_kiri < SRF_kanan)
				{
					servo = 2100;
				}
				else if (SRF_kanan < SRF_kiri)
				{
					servo = 900;
				}
			}
			if (servo > 1700 || servo < 1300)
			{
				speed_kiri = speed_misi4 + 75;
			}
			if (SRF2 < 40 || SRF3 < 40)
			{
				kontrol_mundur(1240);
			}
			break;
		case 5:
			emit change_servo_camera(1800,1500);
			if (timer_misi5 == false)
			{
				timeout_misi = false;
				timer_mission->start(timeout_misi5); // awalnya 100000
				timer_misi5 = true;
			}
			if (timeout_misi)
			{
				speed_kiri = speed_misi5;
				servo = kontrol_navigasi();
				if (SRF1 < 210 || SRF2 < 210 || SRF3 < 210 || SRF4 < 210)
				{
					if (SRF_kiri < SRF_kanan)
					{
						servo = 2100;
					}
					else if (SRF_kanan < SRF_kiri)
					{
						servo = 900;
					}
				}
				if (SRF2 < 45 || SRF3 < 45)
				{
					kontrol_mundur(1000);
				}
			}
			else {
				speed_kiri = speed_imgproc;
				//servo = servo_imgproc2;

				if (speed_kiri > 1590 && speed_kiri < 1780) // ngejar
				{
					speed_kiri = speed_misi5;
				}
				else if (speed_kiri < 1570) //deket
				{
					speed_kiri = speed_misi5_bawah;
				}
				else if (speed_kiri > 1790)//ilang
				{
					speed_kiri = speed_misi5;
					servo = 950;
				}
				if (SRF5 < 600)
				{
					servo = kontrol_tembok(setpoint_misi5);
				}
				else {
					servo = 950;
				}
				
				if (servo > 1750)
				{
					servo = 1750;
				}

				if (SRF1 < 160 || SRF2 < 160 || SRF3 < 160 || SRF4 < 160)
				{
					servo = 2150;
					speed_kiri = 1600;

				}
				if (SRF2 < 85 && SRF3 < 85)
				{
					kontrol_mundur(1000);
				}
			}
			break;
		case 6:
			speed_kiri = speed_misi6;
			//servo = servo_imgproc;
			break;

		case 7:
			speed_kiri = speed_return;
			servo = kontrol_navigasi();
			if (SRF1 < 180 || SRF2 < 180 || SRF3 < 180 || SRF4 < 180)
			{
				if (SRF_kiri < SRF_kanan)
				{
					servo = 2100;
				}
				else if (SRF_kanan < SRF_kiri)
				{
					servo = 900;
				}
			}
			break;
		}
		if (servo > 2150)
		{
			servo = 2150;
		}
		else if (servo < 850)
		{
			servo = 850;
		}
		if (state_mundur == true) // jika kontrol_mundur dipanggil
		{
			speed_kiri = 1250;
			servo = 1500;
		}

		if (status_waypoint == false)  // jika kondisi belum start mission 
		{
			servo = 1500;
			speed_kiri = 1500;
		}
	}
	speed_kanan = speed_kiri + trim;
	servo_kiri = servo + trim_servo_kiri;
	servo_kanan = servo + trim_servo_kanan;

	emit kirim_data_kontrol(servo_kiri,servo_kanan,speed_kiri,speed_kanan,sudutTujuan,errorSudut,jarak,speed_tengah);
	emit kirim_ke_serial(servo_kiri,servo_kanan, speed_kiri, speed_kanan, speed_tengah);

	if (mission_state != mission_state_sebelum || status_misi3 != status_misi3_sebelum) 
	{
		emit status_misi(mission_state, status_misi3);
		emit mission_changed(mission_state);
	}
	mission_state_sebelum = mission_state;
	status_misi3_sebelum = status_misi3;
}


void KontrolKapal::kontrol_mundur(int milisec)
{	
	state_mundur = true;
	timer_mundur->start(milisec);
}

void KontrolKapal::tidak_mundur()
{
	state_mundur = false;
	timer_mundur->stop();
}

void KontrolKapal::stop_rotate()
{
	timer_rotate_misi3->stop();
	status_misi3++;
}

int KontrolKapal::kontrol_navigasi()
{
	sudutCompass = (atan2((latt_waypoint[index_plot_waypoint] - latt_kontrol), (long_waypoint[index_plot_waypoint] - long_kontrol))*(180 / PI));
	sudutTujuan = fmod((450.0 - sudutCompass), 360.0);
	errorSudut = sudutTujuan - comp_kontrol;
	speed_tengah = 1495;

	if (errorSudut > 179.9)
	{
		errorSudut = errorSudut - 360;
	}
	else if (errorSudut < -179.9)
	{
		errorSudut = errorSudut + 360;
	}

	servo_nav = 1500 + ((kontrol_navigasi_P * errorSudut) + (kontrol_navigasi_D * (errorSudut - errorSebelum)) + (kontrol_navigasi_I * (errorSudut + errorSebelum)));

	errorSebelum = errorSudut;

	return servo_nav;
}

int KontrolKapal::kontrol_tembok(int setpoint)
{
	error_misi3 = setpoint - SRF5;
	servo = 1500 + (kontrol_navigasi_P * error_misi3) + (kontrol_navigasi_D * (error_misi3 - error_misi3_sebelum)) + (kontrol_navigasi_I * (error_misi3 + error_misi3_sebelum));
	error_misi3_sebelum = error_misi3;

	return servo;
}

void KontrolKapal::next_mission()
{
	timer_mission->stop();
	timeout_misi = true;
	qDebug() << "Berhasil Timeout";
}

void KontrolKapal::updateDockDrone(int d) {
	second_dock = d;
}