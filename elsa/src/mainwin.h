//An Nguyen

#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include <string>
#include "entrydialog.h"
#include <fstream>

class Mainwin : public Gtk::Window
{
public:
	Mainwin();
	virtual ~Mainwin();
protected:
	void on_save_click();
	void on_save_as_click();
	void on_open_click();
	void on_quit_click();
	void on_view_peripheral_click();
	void on_view_desktop_click();
	void on_view_order_click();
	void on_view_customer_click();
	void on_insert_peripheral_click();
	void on_insert_desktop_click();
	void on_insert_order_click();
	void on_insert_customer_click();
	void on_ram_click();
	void on_disk_click();
	void on_other_click();
	void on_easter_egg_click();
	void on_about_click();
	std::string get_string(std::string prompt);
	double get_double(std::string prompt);
	int get_int(std::string prompt);
	void set_data(std::string s);
	void set_msg(std::string s);
private:
	Store* store;
	Gtk::Label* data;
	Gtk::Label* msg;
	Gtk::Label* welcome;
	Gtk::Stack* stack;
	Gtk:: ScrolledWindow* m_ScrolledWindow;
	Gtk::Image* image;
	Gtk::Box* menuBox;
	Gtk::Box* stackBox;
	Gtk::Box* vbox;
	Gtk::Box* home;
	Gtk::Box* statBox;
	Gtk::Box* main;
	std::string filename;
};
#endif
