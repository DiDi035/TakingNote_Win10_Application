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

		Grid^ textBoxGrid = ref new Grid();
		textBoxGrid->Height = 230;
		textBoxGrid->Width = 490;

		TextBox^ noteTextBox = ref new TextBox();
		noteTextBox->Name = noteId;
		noteTextBox->Width = 490;
		noteTextBox->Height = 200;
		noteTextBox->Header = "No." + noteId; // +"                         Tag: " + tagContent;
		noteTextBox->TextWrapping = TextWrapping::Wrap;
		noteTextBox->AcceptsReturn = true;
		noteTextBox->Text = noteContent;
		noteTextBox->RequestedTheme = Windows::UI::Xaml::ElementTheme::Dark;
		//noteTextBox->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::White);
		//noteTextBox->BorderThickness = 2;
		noteTextBox->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
		textBoxGrid->Children->Append(noteTextBox);

		StackPanel^ tagStackPanel = ref new StackPanel();
		tagStackPanel->Height = 33;
		tagStackPanel->Width = 420; 
		tagStackPanel->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
		tagStackPanel->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Right;
		//tagStackPanel->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::Aqua);
		//tagStackPanel->BorderThickness = 1;
		tagStackPanel->Orientation = Windows::UI::Xaml::Controls::Orientation::Horizontal;
		tagStackPanel->Margin = Windows::UI::Xaml::Thickness(0,15,0,0);
		textBoxGrid->Children->Append(tagStackPanel);

		vector<string> tagList = listNote[i].get_list_tags();
		int tagListSize = tagList.size();
		for (int j = 0; j < tagListSize; ++j) {
			Button^ tagButton = ref new Button();
			tagButton->Height = 33;
			tagButton->Width = tagList[j].length()*9;
			tagButton->BorderBrush = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
			tagButton->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
			tagButton->BorderThickness = 2;
			String^ tagStringStore = stringConverter.convert_from_string_to_String(tagList[j].c_str());
			tagButton->Content = tagStringStore;
			tagStackPanel->Children->Append(tagButton);
		}

		Button^ addMulTag = ref new Button();
		addMulTag->Background = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
		addMulTag->Height = 27;
		addMulTag->Width = 60;
		addMulTag->Content = "Add Tag";
		addMulTag->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Black);
		addMulTag->FontSize = 10;
		addMulTag->Margin = Windows::UI::Xaml::Thickness(3, 3, 0, 0);
		addMulTag->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
		addMulTag->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
		addMulTag->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::openAddMulTagPane_Click);

		textBoxGrid->Children->Append(addMulTag);

		SplitView^ addTagPane = ref new SplitView();

		StackPanel^ addMulTagStack = ref new StackPanel();
		addTagPane->Pane = addMulTagStack;
		addMulTagStack->Height = 0;
		addMulTagStack->Width = 150;
		addMulTagStack->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
		addMulTagStack->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
		addMulTagStack->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
		addMulTagStack->BorderBrush = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
		addMulTagStack->BorderThickness = 2;

		addTagPane->Width = 150;
		addTagPane->Height = 0;
		addTagPane->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
		addTagPane->DisplayMode = SplitViewDisplayMode::CompactInline;
		addTagPane->PaneBackground = ref new SolidColorBrush(Windows::UI::Colors::Black);
		addTagPane->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
		addTagPane->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Left;
		addTagPane->Margin = Windows::UI::Xaml::Thickness(68, 0, 0, 0);
		addTagPane->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		addTagPane->OpenPaneLength = 150;

		addTagPane->Height += 35 * numTotalTag;
		addMulTagStack->Height += 35 * numTotalTag;

		for (int j = 0; j < numTotalTag; ++j) {
			String^ tagContent = stringConverter.convert_from_string_to_String(listTag[j].get_text());
			Button^ tag = ref new Button();
			tag->Content = tagContent;
			tag->Width = 150;
			tag->Height = 35;
			tag->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
			tag->Foreground = ref new SolidColorBrush(Windows::UI::Colors::White);
			tag->Opacity = 2;
			tag->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::addMulTagToNote_Click);
			addMulTagStack->Children->Append(tag);
		}

		textBoxGrid->Children->Append(addTagPane);
		
		stackPanelViewNote->Children->Append(textBoxGrid);

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
					Grid^ grid = (Grid^)stackPanelViewNote->Children->GetAt(j);
					TextBox^ textBox = (TextBox^)grid->Children->GetAt(0);
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
		tag->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::viewAllNoteOfTag_CLick);
		gridAddTag->Children->Append(tag);
	}
}


void OOPLab_Final::MainPage::searchButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (!searchBar->Text->IsEmpty()) {
		String^ searchBarText = searchBar->Text;
		string stringSearchBar = strToStringConverter.convert_from_String_to_string(searchBarText);
		int stackPanelViewNoteSize = stackPanelViewNote->Children->Size;
		for (int i = 0; i < stackPanelViewNoteSize; ++i) {
			Grid^ gridStore = (Grid^)stackPanelViewNote->Children->GetAt(i);
			TextBox^ textBoxStore = (TextBox^)gridStore->Children->GetAt(0);
			String^ textBoxContent = textBoxStore->Text;
			string stringTextBox = strToStringConverter.convert_from_String_to_string(textBoxContent);
			bool check = KMP::search_pattern_in_string(stringSearchBar, stringTextBox);
			if (!check) {
				gridStore->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
			}
		}
	}
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
	Grid^ textBoxGrid = ref new Grid();
	textBoxGrid->Height = 230;
	textBoxGrid->Width = 490;

	numTotalNote++;
	listNote.push_back(Note(numTotalNote, ""));
	stringstream ss;
	ss << listNote[numTotalNote-1].get_id();
	String^ noteId = stringConverter.convert_from_string_to_String(ss.str());
	TextBox^ noteTextBox = ref new TextBox();
	noteTextBox->Name = noteId;
	noteTextBox->Width = 490;
	noteTextBox->Height = 200;
	noteTextBox->Header = "No." + noteId; // +"                         Tag: " + tagContent;
	noteTextBox->TextWrapping = TextWrapping::Wrap;
	noteTextBox->AcceptsReturn = true;
	noteTextBox->RequestedTheme = Windows::UI::Xaml::ElementTheme::Dark;
	noteTextBox->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
	textBoxGrid->Children->Append(noteTextBox);

	StackPanel^ tagStackPanel = ref new StackPanel();
	tagStackPanel->Height = 33;
	tagStackPanel->Width = 420;
	tagStackPanel->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
	tagStackPanel->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Right;
	//tagStackPanel->BorderBrush = ref new SolidColorBrush(Windows::UI::Colors::Aqua);
	//tagStackPanel->BorderThickness = 1;
	tagStackPanel->Orientation = Windows::UI::Xaml::Controls::Orientation::Horizontal;
	tagStackPanel->Margin = Windows::UI::Xaml::Thickness(0, 15, 0, 0);
	textBoxGrid->Children->Append(tagStackPanel);

	stackPanelViewNote->Children->Append(textBoxGrid);

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
		tag->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::viewAllNoteOfTag_CLick);
		gridAddTag->Children->Append(tag);

		int stackPanelViewNoteSize = stackPanelViewNote->Children->Size;
		for (int i = 0; i < stackPanelViewNoteSize; ++i) {
			Button^ tag = ref new Button();
			tag->Content = textBoxAddTag->Text;
			tag->Width = 150;
			tag->Height = 35;
			tag->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
			tag->Foreground = ref new SolidColorBrush(Windows::UI::Colors::White);
			tag->Opacity = 2;
			tag->Click += ref new RoutedEventHandler(this, &OOPLab_Final::MainPage::addMulTagToNote_Click);

			Grid^ gridViewNote = (Grid^)stackPanelViewNote->Children->GetAt(i);
			SplitView^ splitViewNote = (SplitView^)gridViewNote->Children->GetAt(3);
			StackPanel^ tagStackPanel = (StackPanel^)splitViewNote->Pane;
			splitViewNote->Height += 35;
			tagStackPanel->Height += 35;

			tagStackPanel->Children->Append(tag);
		}
	}
}


void OOPLab_Final::MainPage::saveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int childrenCountStackPanel = stackPanelViewNote->Children->Size;
	for (auto i = 0; i < childrenCountStackPanel; ++i) {
		Grid^ noteGrid = (Grid^)stackPanelViewNote->Children->GetAt(i);
		TextBox^ noteTextBox = (TextBox^)noteGrid->Children->GetAt(0);
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


void OOPLab_Final::MainPage::back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	tagToDelete = "";
	int stackPanelViewNoteSize = stackPanelViewNote->Children->Size;
	for (int i = 0; i < stackPanelViewNoteSize; ++i) {
		Grid^ gridStore = (Grid^)stackPanelViewNote->Children->GetAt(i);
		if (gridStore->Visibility == Windows::UI::Xaml::Visibility::Collapsed) {
			gridStore->Visibility = Windows::UI::Xaml::Visibility::Visible;
		}
		StackPanel^ stackPanel = (StackPanel^)gridStore->Children->GetAt(1);
		int tagButtonLSize = stackPanel->Children->Size;
		for (int j = 0; j < tagButtonLSize; ++j) {
			Button^ tagButton = (Button^)stackPanel->Children->GetAt(j);
			tagButton->BorderBrush = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
			tagButton->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
			tagButton->Foreground = ref new SolidColorBrush(Windows::UI::Colors::White);
		}
	}
}

void OOPLab_Final::MainPage::viewAllNoteOfTag_CLick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) 
{
	Button^ currButtonTag = (Button^)sender;
	String^ tagViewNote = currButtonTag->Content->ToString();
	tagToDelete = tagViewNote;
	int stackPanelViewNoteSize = stackPanelViewNote->Children->Size;
	for (int i = 0; i < stackPanelViewNoteSize; ++i) {
		Grid^ gridStore = (Grid^)stackPanelViewNote->Children->GetAt(i);
		int childrenSize = gridStore->Children->Size;
		bool check = false;
		for (int j = 0; j < childrenSize; ++j) {
			Object^ getChild = gridStore->Children->GetAt(j);
			String^ tmp = getChild->GetType()->ToString();
			string temp = strToStringConverter.convert_from_String_to_string(tmp);
			//Windows.UI.Xaml.COntrols.
			if (getChild->GetType()->ToString() == "Windows.UI.Xaml.Controls.StackPanel") {
				StackPanel^ tagStackPanel = (StackPanel^)getChild;
				int tagStackPanelSize = tagStackPanel->Children->Size;
				for (int k = 0; k < tagStackPanelSize; ++k) {
					Button^ tagButton = (Button^)tagStackPanel->Children->GetAt(k);
					String^ checkTagViewNote = tagButton->Content->ToString();
					if (checkTagViewNote == tagViewNote) {
						tagButton->Background = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
						tagButton->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Black);
						check = true;
						break;
					}
				}
				break;
			}
		}
		if (!check) {
			gridStore->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		}
	}
}

void OOPLab_Final::MainPage::DeleteTag_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int stackPanelViewNoteSize = stackPanelViewNote->Children->Size;
	for (int i = 0; i < stackPanelViewNoteSize; ++i) {
		Grid^ gridStore = (Grid^)stackPanelViewNote->Children->GetAt(i);

		SplitView^ splitViewNote = (SplitView^)gridStore->Children->GetAt(3);
		StackPanel^ tagStackPanel = (StackPanel^)splitViewNote->Pane;
		int size = tagStackPanel->Children->Size;
		for (int j = 0; j < size; ++j) {
			Button^ tag = (Button^)tagStackPanel->Children->GetAt(j);
			if (tag->Content->ToString() == tagToDelete) {
				tagStackPanel->Children->RemoveAt(j);
				splitViewNote->Height -= 35;
				tagStackPanel->Height -= 35;
				break;
			}
		}

		StackPanel^ stackPanel = (StackPanel^)gridStore->Children->GetAt(1);
		int tagButtonLSize = stackPanel->Children->Size;
		for (int j = 0; j < tagButtonLSize; ++j) {
			Button^ tagButton = (Button^)stackPanel->Children->GetAt(j);
			if (tagButton->Content->ToString() == tagToDelete) {
				stackPanel->Children->RemoveAt(j);
				break;
			}
		}
	}
	stackPanelViewNoteSize = gridAddTag->Children->Size;
	for (int i = 0; i < stackPanelViewNoteSize; ++i) {
		Button^ tagButton = (Button^)gridAddTag->Children->GetAt(i);
		if (tagButton->Content->ToString() == tagToDelete) {
			gridAddTag->Children->RemoveAt(i);
			gridAddTag->Height -= 35;
			opSplitView->Height -= 35;
			break;
		}
	}
	string stringStore = strToStringConverter.convert_from_String_to_string(tagToDelete);
	for (int i = 0; i < numTotalTag; ++i) {
		if (listTag[i].get_text() == stringStore) {
			listTag.erase(listTag.begin() + i);
			numTotalTag--;
			break;
		}
	}
}

void OOPLab_Final::MainPage::addMulTagToNote_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	Button^ curButton = (Button^)sender;
	String^ contentCurButton = curButton->Content->ToString();
	int gridSize = stackPanelViewNote->Children->Size;
	for (int i = 0; i < gridSize; ++i) {
		Grid^ currGridNote = (Grid^)stackPanelViewNote->Children->GetAt(i);
		TextBox^ currTextBox = (TextBox^)currGridNote->Children->GetAt(0);
		if (currTextBox->Header->ToString() == noteToAddTag) {
			Button^ tagButton = ref new Button();
			tagButton->Height = 33;
			tagButton->Width = contentCurButton->Length() * 9;
			tagButton->BorderBrush = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 12, 191, 123));
			tagButton->Background = ref new SolidColorBrush(Windows::UI::Colors::Black);
			tagButton->BorderThickness = 2;
			tagButton->Content = contentCurButton;
			StackPanel^ tagStackPanel = (StackPanel^)currGridNote->Children->GetAt(1);
			tagStackPanel->Children->Append(tagButton);
			string stringStore = strToStringConverter.convert_from_String_to_string(contentCurButton);
			for (int j = 0; j < numTotalTag; ++j) {
				if (listTag[j].get_text() == stringStore) {
					listTag[j].add_note(i+1);
					break;
				}
			}
			break;
		}
	}
}

void OOPLab_Final::MainPage::openAddMulTagPane_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
	Button^ currButton = (Button^)sender;
	Grid^ currGridParent = (Grid^)VisualTreeHelper::GetParent(currButton);
	TextBox^ currTextBox = (TextBox^)currGridParent->Children->GetAt(0);
	noteToAddTag = currTextBox->Header->ToString();
	SplitView^ currSplitView = (SplitView^)currGridParent->Children->GetAt(3);
	if (currSplitView->Visibility != Windows::UI::Xaml::Visibility::Visible) {
		currSplitView->Visibility = Windows::UI::Xaml::Visibility::Visible;
		currSplitView->IsPaneOpen = !currSplitView->IsPaneOpen;
	}
	else {
		currSplitView->IsPaneOpen = !currSplitView->IsPaneOpen;
		currSplitView->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	}
}
