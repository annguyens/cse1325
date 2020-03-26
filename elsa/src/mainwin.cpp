#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() : store{nullptr} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("ELSA");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem* menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
	
	//  V I E W
	Gtk::MenuItem* menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu* viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//  I N S E R T
	Gtk::MenuItem* menuitem_insert = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu* insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem* menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    vbox->add(*toolbar);

    //     Q U I T
    // Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);

    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);
    

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_view_peripheral_click() {}

void Mainwin::on_view_desktop_click() {}

void Mainwin::on_view_order_click() {}

void Mainwin::on_view_customer_click() {}

void Mainwin::on_insert_peripheral_click() {}

void Mainwin::on_insert_desktop_click() {}

void Mainwin::on_insert_order_click() {}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
/*
    auto logo = Gdk::Pixbuf::create_from_file("128px-Pyramidal_matches.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2017-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"George F. Rice"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by M0tty, licensed under CC BY-SA 3.0 https://commons.wikimedia.org/wiki/File:Pyramidal_matches.svg",
        "Robot by FreePik.com, licensed for personal and commercial purposes with attribution https://www.freepik.com/free-vector/grey-robot-silhouettes_714902.htm"};
    dialog.set_artists(artists);
*/
    dialog.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

std::string Mainwin::get_string(std::string prompt) {}

double Mainwin::get_double(std::string prompt) {}

int Mainwin::get_int(std::string prompt) {}

void Mainwin::set_data(std::string s) {}

void Mainwin::set_msg(std::string s) {}

