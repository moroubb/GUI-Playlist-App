#pragma once
#include "Repo.h"
#include "FileRepo.h"
#include "SongController.h"

class RepositoryTest {
public:
    static void test() {
        SongRepo repository;

        // Test storing songs
        Song song1("Artist1", "Title1", " ", " ",2002);
        repository.store(song1);

        Song song2("Artist2", "Title2"," "," ",2003);
        repository.store(song2);

        // Test retrieving songs
        const Song* retrievedSong =&repository.find("Title1", "Artist1");   
        if (retrievedSong) {
            std::cout << "Retrieved Song: " << retrievedSong->getTitle() << " by " << retrievedSong->getArtist() << std::endl;
        }
        else {
            std::cout << "Song not found." << std::endl;
        }
    }
};


class FileRepositoryTest {
public:
    static void test() {
        FileRepository fileRepository("songs.txt");

        // Test loading songs from file
        fileRepository.load();

        // Test retrieving songs
        const Song* retrievedSong = &fileRepository.find("Title1", "Artist1");
        if (retrievedSong) {
            std::cout << "Retrieved Song: " << retrievedSong->getTitle() << " by " << retrievedSong->getArtist() << std::endl;
        }
        else {
            std::cout << "Song not found." << std::endl;
        }
    }
};



class SongControllerTest {
public:
    static void test() {
        SongRepo repository;
        SongController controller;

        // Test adding songs
        try {
            controller.add("Title1", "Artist1"," "," ", 1999);
            controller.add("Title2", "Artist2"," "," ", 1998);
        }
        catch (const SongException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // Test retrieving songs
        const Song* retrievedSong = &repository.find("Title1", "Artist1");
        if (retrievedSong) {
            std::cout << "Retrieved Song: " << retrievedSong->getTitle() << " by " << retrievedSong->getArtist() << std::endl;
        }
        else {
            std::cout << "Song not found." << std::endl;
        }
    }
};