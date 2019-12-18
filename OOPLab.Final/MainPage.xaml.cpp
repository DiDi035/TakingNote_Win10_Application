//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace OOPLab_Final;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Storage;
using namespace Windows::Globalization;
using namespace std;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	NoteLoader noteLoader;
	listNote = noteLoader.load_note();
	numTotalNote = noteLoader.get_num_total_note();
	TagLoader tagLoader;
	listTag = tagLoader.load_tag();
	numTotalTag = tagLoader.get_nom_total_tag();
	Helper::combine_listNote_listTag(listTag, listNote);
	put_list_tag_to_UI(numTotalTag);
	put_list_note_to_UI(numTotalNote);

}

void OOPLab_Final::MainPage::put_list_note_to_UI(int numTotalNote) {
	stackPanelDeleteNote->Height = 35 * numTotalNote;
	splitViewDelete->Height = 35 * numTotalNote;
	Button^ note;
	for (int i = 0; i < numTotalNote; ++i) {
		stringstream ss;
		ss << listNote[i].get_id();
		String^ noteId = stringConverter.convert_from_string_to_String(ss.str());
		String^ noteContent = stringConverter.convert_from_string_to_String(listNote[i].get_text());
		string tagString = Helper::combine_list_tag_to_single_string(listNote[i].get_list_tags());
		String^ tagContent = stringConverter.convert_from_string_to_String(tagString);
		TextBox^ noteTextBox = ref new TextBox();
		Button^ addTagToNoteButton = ref new Button();
		noteTextBox->Name = noteId;
		noteTextBox->Width = 490;
		noteTextBox->Name = "1";
		noteTextBox->Height = 200;
		noteTextBox->Header = "No." + noteId; // +"                         Tag: " + tagContent;
		noteTextBox->TextWrapping = TextWrapping::Wrap;
		noteTextBox->AcceptsReturn = true;
		noteTextBox->Text = noteContent;
		noteTextBox->RequestedTheme = Windows::UI::Xaml::ElementTheme::Dark;
		noteTextBox->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::White);
		noteTextBox->BorderThickness = 2;
		stackPanelViewNote->Children->Append(noteTextBox);
		note = ref new Button();
		note->Height = 35;
		note->Width = 150;
		note->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
		note->Content = "No." + noteId;
		note->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::buttonDeleteTag_Click);
		stackPanelDeleteNote->Children->Append(note);
	}
}

void OOPLab_Final::MainPage::buttonDeleteTag_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Button^ button = (Button^)sender;
	String^ buttonContent = button->Content->ToString();
	stringstream ss;
	int size = stackPanelDeleteNote->Children->Size;
	for (int i = 1; i <= size; ++i) {
		ss << "No." << i;
		String^ temp = stringConverter.convert_from_string_to_String(ss.str());
		if (temp == buttonContent) {
			stackPanelDeleteNote->Children->RemoveAt(i - 1);
			stackPanelViewNote->Children->RemoveAt(i - 1);
			listNote.erase(listNote.begin() + (i - 1));
			numTotalNote--;
			stackPanelDeleteNote->Height -= 35;
			splitViewDelete->Height -= 35;
			size = stackPanelDeleteNote->Children->Size;
			for (int j = i - 1; j < size; ++j) {
				//update id of stackPanelDeleteNote children
				Button^ tmp = (Button^)stackPanelDeleteNote->Children->GetAt(j);
				temp = tmp->Content->ToString();
				string stringStore = strToStringConverter.convert_from_String_to_string(temp);
				int length = stringStore.length();
				if (length == 4) {
					char split = stringStore[length - 1];
					stringstream ss;
					ss << split;
					int intStore = stoi(ss.str());
					--intStore;
					stringstream out;
					out << intStore;
					String^ StrStore = stringConverter.convert_from_string_to_String(out.str());
					tmp->Content = "No." + StrStore;
					//update id of list Note
					listNote[j].set_id(intStore);
					//update id of StackPanelViewNote
					TextBox^ textBox = (TextBox^)stackPanelViewNote->Children->GetAt(j);
					textBox->Header = "No." + StrStore;
				}
				else if (length == 5) {
					//later
				}
			}
			return;
		}
		ss.str("");
	}
}

void OOPLab_Final::MainPage::put_list_tag_to_UI(int numTotalTag) {
	opSplitView->Height += 35 * numTotalTag;
	gridAddTag->Height += 35 * numTotalTag;
	for (int i = 0; i < numTotalTag; ++i) {
		String^ tagContent = stringConverter.convert_from_string_to_String(listTag[i].get_text());
		Button^ tag = ref new Button();
		tag->Content = tagContent;
		tag->Width = 200;
		tag->Height = 35;
		tag->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
		tag->Opacity = 2;
		gridAddTag->Children->Append(tag);
	}
}


void OOPLab_Final::MainPage::searchButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void OOPLab_Final::MainPage::opButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (opSplitView->Visibility != Windows::UI::Xaml::Visibility::Visible) {
		opSplitView->Visibility = Windows::UI::Xaml::Visibility::Visible;
		opSplitView->IsPaneOpen = !opSplitView->IsPaneOpen;
	}
	else {
		opSplitView->IsPaneOpen = !opSplitView->IsPaneOpen;
		opSplitView->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	}
}


void OOPLab_Final::MainPage::addNewNote_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	numTotalNote++;
	listNote.push_back(Note(numTotalNote, ""));
	stringstream ss;
	ss << listNote[numTotalNote-1].get_id();
	String^ noteId = stringConverter.convert_from_string_to_String(ss.str());
	TextBox^ noteTextBox = ref new TextBox();
	noteTextBox->Width = 490;
	noteTextBox->Height = 200;
	noteTextBox->Header = "No." + noteId; // +"                         Tag: ";
	noteTextBox->PlaceholderText = "Type your notes here";
	noteTextBox->TextWrapping = TextWrapping::Wrap;
	noteTextBox->AcceptsReturn = true;
	noteTextBox->RequestedTheme = Windows::UI::Xaml::ElementTheme::Dark;
	noteTextBox->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::White);
	noteTextBox->BorderThickness = 2;
	stackPanelViewNote->Children->Append(noteTextBox);

	stackPanelDeleteNote->Height += 35;
	splitViewDelete->Height += 35;
	Button^ note = ref new Button();
	note->Height = 35;
	note->Width = 150;
	note->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
	note->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::buttonDeleteTag_Click);
	note->Content = "No." + noteId;
	stackPanelDeleteNote->Children->Append(note);
	
}


void OOPLab_Final::MainPage::addTagButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (!textBoxAddTag->Text->IsEmpty()) {
		opSplitView->Height += 35;
		gridAddTag->Height += 35;
		string newTagText = strToStringConverter.convert_from_String_to_string(textBoxAddTag->Text);
		numTotalTag++;
		listTag.push_back(Tags(newTagText));
		tagSaver.save_tag_to_file(listTag, numTotalTag);
		Button^ tag = ref new Button();
		tag->Content = textBoxAddTag->Text;
		tag->Width = 200;
		tag->Height = 35;
		tag->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
		tag->Opacity = 2;
		gridAddTag->Children->Append(tag);
	}
}


void OOPLab_Final::MainPage::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int childrenCountStackPanel = stackPanelViewNote->Children->Size;
	for (auto i = 0; i < childrenCountStackPanel; ++i) {
		TextBox^ noteTextBox = (TextBox^)stackPanelViewNote->Children->GetAt(i);
		String^ noteContentStr = noteTextBox->Text;
		string noteContentString = strToStringConverter.convert_from_String_to_string(noteContentStr);
		listNote[i].set_text(noteContentString);
	}
	noteSaver.save_note_to_file(listNote, numTotalNote);
	tagSaver.save_tag_to_file(listTag, numTotalTag);
}


void OOPLab_Final::MainPage::deleteNote_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (splitViewDelete->Visibility != Windows::UI::Xaml::Visibility::Visible) {
		splitViewDelete->Visibility = Windows::UI::Xaml::Visibility::Visible;
		splitViewDelete->IsPaneOpen = !splitViewDelete->IsPaneOpen;
	}
	else {
		splitViewDelete->IsPaneOpen = !splitViewDelete->IsPaneOpen;
		splitViewDelete->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	}
}


void OOPLab_Final::MainPage::stackPanelViewNote_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e)
{

}


void OOPLab_Final::MainPage::stackPanelDeleteNote_Tapped(Platform::Object^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs^ e)
{
	
}
