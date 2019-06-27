def REPO = "Jenkins-Test"
def TESTER = "Test_helper.c"

pipeline {
    agent any
    stages {
    	stage('checkout') {
    		steps {
  				sh "git clone https://github.com/teodutu/${REPO}"
    		}
    	}
    	stage('hello') {
    		steps {
    			sh "echo \"Gonna start building...\""
    		}
    	}
    	stage('check compiler') {
    		steps {
    			sh 'gcc --version'
    		}
    	}
        stage('build helper') {
            steps {
                sh "make build helper.o -C ${REPO}/src && echo \"Header built successully!\" || echo \"Failed to build!\""
            }
        }
        stage('make and build tester') {
            steps {
                sh "ruby ${REPO}/generators/generate_test_runner.rb ${REPO}/tests/${TESTER}" // autogenerate Runner file for the tests
                sh "make build -C ${REPO}/tests && echo \"Tester built successully!\" || echo \"Failed to build tester!\""
            }
        }
        stage('test header') {
        	steps {
                echo "Testing functions..."
        		sh "make run -C ${REPO}/tests"
        	}
        }
        stage('build project') {
            steps {
                sh "make build -C ${REPO}/src && echo \"Built successully!\" || echo \"Failed to build!\""
            }
        }
        stage('clean') {
        	steps {
        		sh "make -C ${REPO} clean"
        		sh "rm -rf ${REPO}"
        	}
        }
    }
}