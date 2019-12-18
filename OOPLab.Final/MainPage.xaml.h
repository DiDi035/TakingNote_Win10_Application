//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "MainBoard.h"

namespace OOPLab_Final
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>

	public ref class MainPage sealed
	{
	public:
		MainPage();
	private:
		vector<Note> listNote;
		vector<Tags> listTag;
		int numTotalNote;
		int numTotalTag;
		TagSaver tagSaver;
		NoteSaver noteSaver;
		stringToStringConverter stringConverter;
		StrToIntConverter strIntCOnverter;
		StrTostring strToStringConverter;
		void put_list_tag_to_UI(int numTotalTag);
		void put_list_note_to_UI(int numTotalNote);
		void searchButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void opButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addNewNote_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void addTagButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void deleteNote_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void stackPanelViewNote_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
		void stackPanelDeleteNote_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e);
		void buttonDeleteTag_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
