pipeline {
    agent none

    stages {
        stage("Build") {
            parallel {

                stage("Windows build") {
                    agent { label "windows" }
                    matrix {
			axis {
				name 'BUILD_TYPE'
				values 'Debug', 'Release'
			}
		    
                    stages {
                        stage("Checkout") {
                            steps { checkout scm }
                        }
                        stage("Configure") {
                            steps {
                                bat """
                                    if exist build rmdir /s /q build
                                    mkdir build
                                    cmake -S . -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
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
                }

                stage("Linux build") {
                    agent { label "linux" }
		    matrix {
			axis {
			    name 'BUILD_TYPE'
		  	    values 'Debug', 'Release'
			}	
                    stages {
                        stage("Checkout") {
                            steps { checkout scm }
                        }
                        stage("Configure") {
                            steps {
                                sh """
                                    rm -rf build
                                    mkdir build
                                    cmake -S . -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
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
}

