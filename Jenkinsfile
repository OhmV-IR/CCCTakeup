pipeline {
    agent none

    stages {
        stage("Build") {
            parallel {

                stage("Windows build") {
                    agent { label "windows" }
                    stages {
                        stage("Checkout") {
                            steps { checkout scm }
                        }
                        stage("Configure") {
                            steps {
                                bat """
                                    if exist build rmdir /s /q build
                                    mkdir build
                                    cmake -S . -B build
                                """
                            }
                        }
                        stage("Build") {
                            steps {
                                bat "cmake --build build"
                            }
                        }
                    }
                }

                stage("Linux build") {
                    agent { label "linux" }
                    stages {
                        stage("Checkout") {
                            steps { checkout scm }
                        }
			stage("deps"){
				steps {
					sh "sudo apt install -y build-essential cmake ninja-build"
				}
			}
                        stage("Configure") {
                            steps {
                                sh """
                                    rm -rf build
                                    mkdir build
                                    cmake -S . -B build
                                """
                            }
                        }
                        stage("Build") {
                            steps {
                                sh "cmake --build build"
                            }
                        }
                    }
                }

            }
        }
    }
}

