#ifndef APP_WINDOW
#define APP_WINDOW

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm.h>
#include <vector>

class AppWindow : public Gtk::Window{
	public:
		AppWindow();
		virtual ~AppWindow();
	protected:
	  // Container:
  	Gtk::Box m_Box;
    Gtk::Box s_Box;

  	// Widgets:
  	Gtk::HeaderBar m_HeaderBar;
  	Gtk::StackSidebar m_StackSidebar;
  	Gtk::Separator m_Separator;
  	Gtk::Stack m_Stack;
    Gtk::Button button1;
    Gtk::Button button2;
    Gtk::Box page1;
    Gtk::Box page2;
    Gtk::Button i_button;
};

#endif
