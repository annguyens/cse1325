#include "mainwin.h"
#include "ram.h"
#include <iostream> // for std::cerr logging
#include <sstream>

int global = 1;

Mainwin::Mainwin() : store{nullptr} {
	// /////////////////
	// G U I   S E T U P
	// /////////////////
	
	delete store;
	store = new Store();
	filename = "untitled.elsa";
   	set_default_size(450, 350);
    	set_title("ELSA");
	
	main = Gtk::manage(new Gtk::VBox);
	add(*main);
     ///////////////////////////////////////////////////////
    // M E N U
   // Add a menu bar as the top item in the vertical box
	menuBox=Gtk::manage(new Gtk::VBox);
	main->pack_start(*menuBox, Gtk::PACK_SHRINK, 0);
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    menuBox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	
	 //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem* menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

	//         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem* menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
	menuitem_quit->set_tooltip_markup("Exit");
	
	//        OPEN
	Gtk::MenuItem* menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open",true));
	menuitem_open->signal_activate().connect([this]{this->on_open_click();});
	filemenu->append(*menuitem_open);

	//		SAVE
    Gtk::MenuItem* menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);


//  	  SAVE AS
    Gtk::MenuItem* menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
	
	//  V I E W
	Gtk::MenuItem* menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu* viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//         CUSTOMER
    // Append Customer to the View menu
    Gtk::MenuItem* menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);
	menuitem_customer->set_tooltip_markup("View list of customers");

	//         PERIPHERAL
    // Append Peripheral to the View menu
    Gtk::MenuItem* menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);
	menuitem_peripheral->set_tooltip_markup("View list of peripherals");

//         DESKTOP
    // Append Desktop to the View menu
    Gtk::MenuItem* menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);
	menuitem_desktop->set_tooltip_markup("View list of products");

//         ORDER
    // Append Order to the View menu
    Gtk::MenuItem* menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);
	menuitem_order->set_tooltip_markup("View list of orders");

//  I N S E R T
	Gtk::MenuItem* menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu* insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);

	//         CUSTOMER
    // Append Customer to the Insert menu
    Gtk::MenuItem* menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_insert_customer);
	menuitem_insert_customer->set_tooltip_markup("Add a new customer");

	
//         PERIPHERAL
    // Append Peripheral to the Insert menu
    Gtk::MenuItem* menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_insert_peripheral);
	menuitem_insert_peripheral->set_tooltip_markup("Add a new option");

	//         DESKTOP
    // Append Desktop to the Insert menu
    Gtk::MenuItem* menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_insert_desktop);
	menuitem_insert_desktop->set_tooltip_markup("Add a new product");

	//         ORDER
    // Append Order to the Insert menu
    Gtk::MenuItem* menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_insert_order);
	menuitem_insert_order->set_tooltip_markup("Add a new order");

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
	menuitem_about->set_tooltip_markup("Click to learn more about ELSA");

	//Scrolled Window as the Window contents
	m_ScrolledWindow= Gtk::manage(new Gtk::ScrolledWindow);
	 m_ScrolledWindow->set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
	main->pack_start(*m_ScrolledWindow, Gtk::PACK_EXPAND_WIDGET, 0);

	stackBox = Gtk::manage(new Gtk::VBox);
	stack = Gtk::manage(new Gtk::Stack);
	stack->set_hexpand(true);
   	stack->set_vexpand(true);
	m_ScrolledWindow->add(*stackBox);
	stackBox->add(*stack);
	

	 // Put vertical box container in Scrolled Window 
   	 vbox = Gtk::manage(new Gtk::VBox);
   	 stack->add(*vbox);

	//DATA DISPLAY
	data = Gtk::manage(new Gtk::Label);
	data->set_hexpand(true);
	data->set_vexpand(true);
	data->set_alignment(0,0);
	stack->add(*data);

	//STATUS BAR DISPLAY
	statBox = Gtk::manage(new Gtk::VBox);
	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	statBox->pack_end(*msg,Gtk::PACK_SHRINK,0);
	main->pack_end(*statBox,Gtk::PACK_SHRINK,0);
	statBox->override_background_color(Gdk::RGBA("#DCDCDC"));

	//ICON 
	auto logo = Gdk::Pixbuf::create_from_file("elsa_logo.png");
	set_icon(logo);

/////////////////////////////////
// W E L C O M E  S C R E E N //
///////////////////////////////

	//Elsa logo
	image = Gtk::manage(new Gtk::Image{"elsa_logo1.png"});
	vbox->pack_start(*image, true, true);
	
	// welcome text
	welcome = Gtk::manage(new Gtk::Label());
	welcome->set_hexpand(true);
	welcome->set_vexpand(true);
	welcome->set_alignment(0,0);
	vbox->pack_start(*welcome,Gtk::PACK_SHRINK,0);
	welcome->set_markup("<span size='x-large' weight='bold'> Welcome to ELSA!</span>\nClick on the menu to get started\n\n");
	welcome->set_halign(Gtk::ALIGN_CENTER);

	// Make the window and everything in it visible
	stack->set_visible_child(*vbox);
	main->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_view_peripheral_click() 
{
	stack->set_visible_child(*data);
	std::ostringstream oss;
	oss <<"<span size='medium' weight='bold'> Peripherals\n\n</span>";
	for(int i=0; i<store->num_options(); i++)
	{
		oss << i << ") " << store->option(i) << "\n"; 
	}
	set_data(oss.str());
}

void Mainwin::on_view_desktop_click() 
{
	stack->set_visible_child(*data);
	std::ostringstream oss;
	oss <<"<span size='medium' weight='bold'> Products\n\n</span>";
	for(int i=0; i<store->num_desktops(); i++)
	{
		oss << i << ") " << store->desktop(i) << "\n"; 
	}
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_order_click() 
{
	stack->set_visible_child(*data);
	welcome->set_markup("");
	std::ostringstream oss;
	oss <<"<span size='medium' weight='bold'> Orders\n\n</span>";
	for(int i=0; i<store->num_orders(); i++)
	{
		oss << i << ") " << store->order(i) << "\n"; 
	}
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_view_customer_click() 
{
	stack->set_visible_child(*data);
	std::ostringstream oss;
	oss <<"<span size='medium' weight='bold'> Customers\n\n</span>";
	for(int i=0; i<store->num_customers(); i++)
	{
		oss << i << ") " << store->customer(i) << "\n"; 
		set_data(oss.str());
	}
	set_data(oss.str());
	set_msg("");
}

void Mainwin::on_insert_peripheral_click() 
{
	Gtk::Dialog* dialog = nullptr;
	try{	
		dialog = new Gtk::Dialog("Insert Peripheral",*this);
		dialog->add_button("RAM",1);
		dialog->add_button("Disk", 3);
		dialog->add_button("Other",2);
		dialog->add_button("Cancel",0);
		dialog->show_all();
		int x = dialog->run();
		
		if(x==1) {on_ram_click();}
		else if(x==2) {on_other_click();}
		else if (x==0) {dialog->close();}
		else if(x==3) {on_disk_click();}

	} catch(std::exception& e)
	{
		std::cerr << "Error:"<< e.what();
	}
	delete dialog;
}

void Mainwin::on_disk_click()
{
	std::string name;
	name = get_string("Name of new disk?");
	Gtk::Dialog* dialog = nullptr;
	try{
		dialog = new Gtk::Dialog("Add Disk", *this);
		dialog->set_default_size(200,100);
		Gtk::Entry tb_entry;
		Gtk::Label tb_label;
		tb_label.set_text("TB  ");
		Gtk::Entry cost_entry;
		Gtk::Label cost_label;
		cost_label.set_text("Cost");
		Gtk::Grid* m_grid = Gtk::manage(new Gtk::Grid);
		m_grid->set_row_homogeneous(true);
		m_grid->set_column_homogeneous(true);
		m_grid->attach(tb_label,0,0,1,1);
		m_grid->attach(tb_entry,1,0,3,1);
		m_grid->attach(cost_label,0,1,1,1);
		m_grid->attach(cost_entry,1,1,3,1);
		dialog->get_content_area()->pack_start(*m_grid);
		
		dialog->add_button("Insert", 1);
		dialog->add_button("Cancel", 0);
		dialog->show_all();
		int x = dialog->run();
		
		if(x)
		{
			double cost = std::stod(cost_entry.get_text());
			int tb = std::stoi(tb_entry.get_text());
			Disk disk{tb,name,cost};
			store->add_option(disk);
			on_view_peripheral_click();
			std::string s = "Added peripheral";
			set_msg(s);
		}
		else {dialog->close();}
		
	} catch(std::exception& e){
		std::cerr<< e.what();
	}
	delete dialog;
}

void Mainwin::on_other_click()
{
	std::string name;
	name = get_string("Name of new peripheral?");
	double cost;
	cost = get_double("Cost?");
	if(cost!=-1)
	{
		Options option{name,cost};
		store->add_option(option);
	} 
	on_view_peripheral_click();
	std::string s = "Added peripheral";
	set_msg(s);
}

void Mainwin::on_ram_click()
{
	welcome->set_markup("");
	Gtk::Dialog* dialog = nullptr;
	try{
		dialog = new Gtk::Dialog("Add RAM", *this);
		dialog->set_default_size(200,100);
		Gtk::Entry* gb_entry = Gtk::manage(new Gtk::Entry);
		Gtk::Entry* cost_entry = Gtk::manage(new Gtk::Entry);
		Gtk::Label* gb_label = Gtk::manage(new Gtk::Label);
		gb_label->set_text("GB   ");
		Gtk::Label* cost_label = Gtk::manage(new Gtk::Label);
		cost_label->set_text("Cost");
		Gtk::Grid* m_grid = Gtk::manage(new Gtk::Grid);
		m_grid->set_row_homogeneous(true);
		m_grid->set_column_homogeneous(true);
		m_grid->attach(*gb_label, 0,0,1,1);
		m_grid->attach(*gb_entry,1,0,3,1);
		m_grid->attach(*cost_label,0,1,1,1);
		m_grid->attach(*cost_entry,1,1,3,1);
		dialog->get_content_area()->pack_start(*m_grid);

		dialog->add_button("Insert", 1);
		dialog->add_button("Cancel",0);
		dialog->show_all();
		int x = dialog->run();
		if(x==1)
		{
			int gb = std::stoi(gb_entry->get_text());
			double cost = std::stod(cost_entry->get_text());
			Ram ram{"RAM", cost, gb};
			store->add_option(ram);
			on_view_peripheral_click();
			std::string s = "Added peripheral";
			set_msg(s);
		}
		else {dialog->close();}
	}catch(std::exception& e)
	{
		std::cerr << "Error:" << e.what();
	}
	delete dialog;
}

void Mainwin::on_insert_desktop_click() 
{
	Gtk::Dialog* dialog = nullptr;
	try{
	dialog = new Gtk::Dialog("Add Desktop", *this);
		dialog->set_default_size(300,100);
		Gtk::Grid* m_grid = Gtk::manage(new Gtk::Grid);
		m_grid->set_row_homogeneous(false);
		m_grid->set_column_homogeneous(true);
		Gtk::Label* label=Gtk::manage(new Gtk::Label);
		label->set_text("Choose Peripheral");
		Gtk::Label* list=Gtk::manage(new Gtk::Label);
		Gtk::Label* desktops=Gtk::manage(new Gtk::Label);
		desktops->set_markup("<span weight='bold'> \nDesktop Configurations: </span>");
		Gtk::ComboBoxText* m_Combo= Gtk::manage(new Gtk::ComboBoxText);

		for(int i=0; i<store->num_options(); i++)
		{
			std::ostringstream os;
			os << store->option(i);
			const Glib::ustring s{os.str()};
			const Glib::ustring id{std::to_string(i)};
			m_Combo->append(id,s);
		}
		m_Combo->set_active(1);
		m_grid->attach(*label,0,0,1,1);
		m_grid->attach(*m_Combo,1,0,1,1);
		m_grid->attach(*list,1,1,1,1);
		m_grid->attach(*desktops,0,1,1,1);
		dialog->get_content_area()->pack_start(*m_grid);		
		
		dialog->add_button("Add Peripheral", 1);
		dialog->add_button("Done", 0);
		dialog->show_all();
		int x = dialog->run();
		
		int desktop;
		if(x==1) {desktop = store->new_desktop();}
		else {dialog->close();}
		std::string peripherals="";
		std::string s;
		while(x!=0)
		{
			if(x==1)
			{
			std::string text = m_Combo->get_active_text();
  				
			int option=std::stoi(m_Combo->get_active_id());	
				store->add_option(option,desktop);
			peripherals = peripherals+ "\nAdded" + text;
			list->set_text(peripherals);
			s = "Added Desktop #"+std::to_string(desktop);
			}
			else{dialog->close();}
			 x = dialog->run();
		}
		on_view_desktop_click();
		set_msg(s);
	} catch(std::exception& e)
	{
		std::cerr << "Error:" << e.what();
	}
	delete dialog;

}

void Mainwin::on_insert_order_click() 
{
	int customer = -1;
	int order = -1;
	int desktop = -1;
	int choice = 1;
	Gtk::Dialog* dialog = nullptr;
	try{
		dialog = new Gtk::Dialog("Create Order", *this);
		dialog->set_default_size(200,100);
		Gtk::Grid* m_grid = Gtk::manage(new Gtk::Grid);
		Gtk::Image* cart = Gtk::manage(new Gtk::Image{"shop.png"});
		cart->set_hexpand(true);
		m_grid->set_row_homogeneous(false);
		m_grid->set_column_homogeneous(false);
		Gtk::Label* cust_label=Gtk::manage(new Gtk::Label);
		Gtk::Label* subtotal_label=Gtk::manage(new Gtk::Label);
		subtotal_label->set_markup("<span size='medium' weight='bold'>SUBTOTAL :\n</span>");
		subtotal_label->set_hexpand(true);
		Gtk::Label* subtotal=Gtk::manage(new Gtk::Label);
		cust_label->set_text("Choose Customer   ");
		cust_label->set_halign(Gtk::ALIGN_END);
		Gtk::ComboBoxText* m_Combo= Gtk::manage(new Gtk::ComboBoxText);
		for(int i=0; i<store->num_customers(); i++)
		{
			std::ostringstream os;
			os << store->customer(i).get_name();
			const Glib::ustring s{os.str()};
			const Glib::ustring id{std::to_string(i)};
			m_Combo->append(id,s);
		}
		Gtk::Label* desk_label=Gtk::manage(new Gtk::Label);
		desk_label->set_text("Choose Desktop   ");
		desk_label->set_halign(Gtk::ALIGN_END);
		Gtk::ComboBoxText* n_Combo= Gtk::manage(new Gtk::ComboBoxText);
		Gtk::Label* label=Gtk::manage(new Gtk::Label);
		label->set_markup("<span size='medium' weight='bold'>\nSHOPPING CART\n</span>");
		label->set_hexpand(true);
		label->set_halign(Gtk::ALIGN_END);
		Gtk::Label* list=Gtk::manage(new Gtk::Label);
		list->set_halign(Gtk::ALIGN_END);
		Gtk::Label* price=Gtk::manage(new Gtk::Label);
		for(int i=0; i<store->num_desktops(); i++)
		{
			std::ostringstream ost;
			ost << "Desktop #" << i;
			const Glib::ustring s{ost.str()};
			const Glib::ustring id{std::to_string(i)};
			n_Combo->append(id,s);
		}
		on_view_desktop_click();
		n_Combo->set_active(1);
		m_grid->attach(*cust_label,0,0,1,1);
		m_grid->attach(*m_Combo,1,0,1,1);
		m_grid->attach(*desk_label,0,1,1,1);
		m_grid->attach(*n_Combo,1,1,1,1);
		m_grid->attach(*label,0,2,1,1);
		m_grid->attach(*cart,1,2,1,1);
		m_grid->attach(*list,0,3,1,1);
		m_grid->attach(*price,1,3,1,1);
		m_grid->attach(*subtotal_label,0,4,1,1);
		m_grid->attach(*subtotal,1,4,1,1);
		dialog->get_content_area()->pack_start(*m_grid);		
		
		dialog->add_button("Add To Cart", 1);
		dialog->add_button("Checkout",0);
		dialog->show_all();
		int x = dialog->run();

		if(x==1) 
		{	
			customer=std::stoi(m_Combo->get_active_id());
			order = store->new_order(customer);
			desktop = 0;
		}
		else {dialog->close();}
		std::string s;
		std::string desks="";
		std::ostringstream costs;
		std::stringstream sub;
		double summ =0.00;
		while(x==1)
		{
			if(x==1)
			{
				std::string text = n_Combo->get_active_text();
  				
				desktop=std::stoi(n_Combo->get_active_id());	
				store->add_desktop(desktop,order);
				desks = desks + " Added Desktop #" + std::to_string(desktop) +"\n";
				
				list->set_text(desks);
				costs << "$" << std::fixed << std::setprecision(2)<< ((store->desktop(desktop)).price()) <<"\n";
				price->set_text(costs.str());
				s = "Added Order #" + std::to_string(order);
				summ = summ + store->desktop(desktop).price();
				sub << "<span size='medium' weight='bold'>$" << std::fixed << std::setprecision(2)<< summ << "\n</span>";
				subtotal->set_markup(sub.str());
				sub.str("");
			}
			else
			{dialog->close();}
			desktop = 0;
			 x = dialog->run();
		}
		on_view_order_click();
		set_msg(s);
	}catch(std::exception& e){std::cerr << "Error:" << e.what();}
	delete dialog;
	std::ostringstream oss;
	if(order >=0)
	{	
		oss << "<span size='large' weight='bold'> Order #" << order << " Placed </span>\n\n" << store->order(order);
		Gtk::MessageDialog{*this, oss.str(), true}.run();
	}
	
	
}

void Mainwin::on_insert_customer_click() 
{
	Gtk::Dialog* dialog = nullptr;
	try{
		dialog = new Gtk::Dialog("Insert Customer",*this);
		dialog->set_default_size(290,100);
		Gtk::Entry* name_entry = Gtk::manage(new Gtk::Entry);
		Gtk::Label* name_label = Gtk::manage(new Gtk::Label);
		name_label->set_text("Name ");
		Gtk::Entry* phone_entry = Gtk::manage(new Gtk::Entry);
		Gtk::Label* phone_label = Gtk::manage(new Gtk::Label);
		phone_label->set_text("Phone");
		Gtk::Entry* email_entry = Gtk::manage(new Gtk::Entry);
		Gtk::Label* email_label = Gtk::manage(new Gtk::Label);
		email_label->set_text("Email  ");
		Gtk::Grid* m_grid = Gtk::manage(new Gtk::Grid);
		m_grid->set_row_homogeneous(true);
		m_grid->set_column_homogeneous(true);
		m_grid->attach(*name_label,0,0,1,1);
		m_grid->attach(*name_entry,1,0,4,1);
		m_grid->attach(*phone_label,0,1,1,1);
		m_grid->attach(*phone_entry,1,1,4,1);
		m_grid->attach(*email_label,0,2,1,1);
		m_grid->attach(*email_entry,1,2,4,1);
		name_entry->set_text("John Doe");
		phone_entry->set_text("XXX-XXX-XXXX");
		email_entry->set_text("xxx@domain.com");
		dialog->get_content_area()->pack_start(*m_grid);

		dialog->add_button("Insert", 1);
		dialog->add_button("Cancel",0);
		dialog->show_all();
		int x = dialog->run();
		
		if(x==1)
		{
			std::string name = name_entry->get_text();
			if(name.size())
			{
				std::string phone = phone_entry->get_text();
				std::string email = email_entry->get_text();
				Customer customer{name, phone, email};
				while(!customer.valid_phone()||!customer.valid_email()){
	if(!customer.valid_phone())
	{
		Gtk::MessageDialog{*this,"Invalid Phone Number"}.run();
		x=dialog->run();
		phone = phone_entry->get_text();
		customer.set_phone(phone);
		if(x==0){break;}
	}
	else if(!customer.valid_email()){
		Gtk::MessageDialog{*this,"Invalid Email"}.run();
		x=dialog->run();
		if(x==0){break;}
		email = email_entry->get_text();
		customer.set_email(email);
	}
		}

				if(x==1)
				{
				store->add_customer(customer);
				std::string s = "Added customer " + customer.get_name();
				on_view_customer_click();
				set_msg(s);
				}
			}
		}
		else{dialog->close();}
	} catch (std::exception& e) 
	{
		std::cerr << "Error:"<< e.what();
	}	
	delete dialog;
}

void Mainwin::on_open_click() {
	Gtk::FileChooserDialog dialog("Select a folder", Gtk::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.elsa");

    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

	int result = dialog.run();

    if (result == 1) {
        try {
            	delete store;
		filename = dialog.get_filename();
		std::ifstream ifs{filename};
		store = new Store{ifs};
            if(!ifs) {
		filename= "";
		throw std::runtime_error{"File contents bad"};
		}
        } catch(std::exception& e) {
		//dialog.close();
            Gtk::MessageDialog{*this, "Unable to open store"}.run();	
        }
    }

}
void Mainwin::on_easter_egg_click() 
{
    Customer c{"Bugs Bunny", "817-ACA-RROT", "bugs@loony.tunes"};          store->add_customer(c);
    c = Customer{"Elastigirl", "817-STR-ETCH", "helen@incredibles.movie"}; store->add_customer(c);
    c = Customer{"Tuck and Roll", "817-UFI-RED2", "circus@bugs.life"};     store->add_customer(c);
    c = Customer{"Tiana", "817-NOG-RIMM", "princess@lily.pad"};            store->add_customer(c);

    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"CPU: 300 MHz AM3351BZCEA30R ARM", 11.03}; store->add_option(o);
    o = Options{"CPU: 240 MHz ColdFire MCF5", 17.33};      store->add_option(o);

    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
    o = Options{"16 GB RAM", 92.99};                       store->add_option(o);
    o = Options{"32 GB RAM", 134.96};                      store->add_option(o);
    o = Options{"64 GB RAM", 319.99};                      store->add_option(o);

    o = Options{"0.5 TB SSD", 79.99};                      store->add_option(o);
    o = Options{"1 TB SSD", 109.99};                       store->add_option(o);
    o = Options{"2 TB SSD", 229.99};                       store->add_option(o);
    o = Options{"4 TB SSD", 599.99};                       store->add_option(o);

    o = Options{"1 TB PC Disk", 44.83};                    store->add_option(o);
    o = Options{"2 TB Hybrid Disk", 59.99};                store->add_option(o);
    o = Options{"4 TB Hybrid Disk", 93.98};                store->add_option(o);

    int desktop = store->new_desktop();
    store->add_option(0, desktop);
    store->add_option(9, desktop);
    store->add_option(14, desktop);

    desktop = store->new_desktop();
    store->add_option(1, desktop);
    store->add_option(7, desktop);
    store->add_option(17, desktop);

    desktop = store->new_desktop();
    store->add_option(5, desktop);
    store->add_option(7, desktop);
    store->add_option(15, desktop);
}

void Mainwin::on_save_click() 
{
	try{
		if(filename.empty()) {on_save_as_click();}
		std::ofstream ofs{filename};
		store->save(ofs);
		if(!ofs) {
			throw std::runtime_error{"Error writing file\n"};
		}
	}catch (std::exception& e) {
		set_data("");
		filename="";
		Gtk::MessageDialog{*this,"Unable to save"}.run();	
	}
}

void Mainwin::on_save_as_click() {
	Gtk::FileChooserDialog dialog("Select a file",
	Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);
	
	dialog.set_filename("untitled.elsa");
	
	dialog.add_button("_Cancel", 0);
	dialog.add_button("Save", 1);

	int result = dialog.run();

	if(result == 1){
		try{
			filename = dialog.get_filename();
			on_save_click();
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "Unable to save store data"}.run();		
		}
	}
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
	auto logo = Gdk::Pixbuf::create_from_file("elsa_logo1.png");
	dialog.set_logo(logo);
	dialog.set_version("Version 1.4.1");
	dialog.set_comments("The Exceptional Laptops and Supercomputers Always (ELSA) store offers the coolest deals in computing technology. Each computer can be hand-crafted to match the technologist's exact needs, with a growing selection of pre-defined configurations already purchased by other customers!");
	std::vector<Glib::ustring> authors = {"An Nguyen"};
	dialog.set_authors(authors);
	std::vector<Glib::ustring> artists = {"Ted Kulakevich https://dribbble.com/shots/4921842-Elsa-Logo#shot-description"};
	dialog.set_artists(artists);
    dialog.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

std::string Mainwin::get_string(std::string prompt) 
{
	EntryDialog edialog{*this,prompt,true};
	edialog.run();
	return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) 
{
	EntryDialog edialog{*this,prompt,true};
	edialog.run();
	double x;
	try{
		x = std::stod(edialog.get_text());
	}catch(std::exception& e){
		x = -1.0;
	}
	return x;
}

int Mainwin::get_int(std::string prompt) 
{
	EntryDialog edialog{*this,prompt,true};
	edialog.run();
	int x;
	try{
		x = std::stoi(edialog.get_text());
	}catch(std::exception& e){
		x = -1;
	}
	return x;
}

void Mainwin::set_data(std::string s) {data->set_markup(s);}

void Mainwin::set_msg(std::string s) {msg->set_markup(s);}

