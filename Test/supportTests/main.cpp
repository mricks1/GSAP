/**  supportTests - Entry point
 *   @file      main.cpp
 *
 *   @brief     Run unit tests for support classes
 *
 *   @author    Jason Watkins <jason-watkins@outlook.com>
 *   @version   0.1.0
 *   @date      2016-07-08
 *
 *   @pre       N/A
 *
 *   @copyright Copyright (c) 2016 United States Government as represented by
 *              the Administrator of the National Aeronautics and Space
 *              Administration. All Rights Reserved.
 */

#include <fstream>

#include "Test.h"
#include "ConfigMapTests.h"
#include "DataStoreTests.h"
#include "DPointsTests.h"
#include "DPointTests.h"
#include "MatrixTests.h"
#include "ModelTests.h"
#include "ObserverTests.h"
#include "PEventTests.h"
#include "PredictorTests.h"
#include "ProgDataTests.h"
#include "ThreadTests.h"
#include "UDataTests.h"
#include "TCPTests.h"
#include "UDPTests.h"
using namespace PCOE::Test;

int main() {
    TestContext context;
    // Config Map Tests
    context.AddTest("Init", configMapInit, "Config Map");
    context.AddTest("Use", configMapUse, "Config Map");
    context.AddTest("Load", configMapLoad, "Config Map");
    context.AddTest("GSAP Init", gsapConfigMapInit, "Config Map");
    context.AddTest("GSAP Use", gsapConfigMapUse, "Config Map");

    // UData Tests
    context.AddTest("construct_default", TestUData::construct_default, "UData");
    context.AddTest("construct_type", TestUData::construct_type, "UData");
    context.AddTest("construct_copy", TestUData::construct_copy, "UData");
    context.AddTest("construct_move", TestUData::construct_move, "UData");
    context.AddTest("operator_assign", TestUData::operator_assign, "UData");
    context.AddTest("operator_equal", TestUData::operator_equal, "UData");
    context.AddTest("operator_notequal", TestUData::operator_notequal, "UData");
    context.AddTest("dist", TestUData::dist, "UData");
    context.AddTest("npoints", TestUData::npoints, "UData");
    context.AddTest("size", TestUData::size, "UData");
    context.AddTest("uncertainty", TestUData::uncertainty, "UData");
    context.AddTest("updated", TestUData::updated, "UData");
    context.AddTest("valid", TestUData::valid, "UData");
    context.AddTest("operator_not", TestUData::operator_not, "UData");
    context.AddTest("iterators_forward", TestUData::iterators_forward, "UData");
    context.AddTest("iterators_reverse", TestUData::iterators_reverse, "UData");
    context.AddTest("access_double", TestUData::access_double, "UData");
    context.AddTest("access_pair", TestUData::access_pair, "UData");
    context.AddTest("access_vector", TestUData::access_vector, "UData");
    context.AddTest("point", TestUData::point, "UData");
    context.AddTest("meanSD", TestUData::meanSD, "UData");
    context.AddTest("meanCovar", TestUData::meanCovar, "UData");
    context.AddTest("percentiles", TestUData::percentiles, "UData");
    context.AddTest("samples", TestUData::samples, "UData");
    context.AddTest("wSamples", TestUData::wSamples, "UData");

    // DStore Tests
    context.AddTest("Init", DStoreInit, "DStore");
    context.AddTest("Use", DStoreUse, "DStore");

    // DPoints Tests
    context.AddTest("Initialization", testPEventsInit, "DPoints");
    context.AddTest("DPoint Init", testDPointsInit, "DPoints");
    context.AddTest("P Event Update", testPEventsUpdate, "DPoints");
    context.AddTest("D Point Update", testDPointsUpdate, "DPoints");

    // DPoint Tests
    context.AddTest("Initialization", testDPointInit, "DPoint");
    context.AddTest("Meta", testDPointMeta, "DPoint");
    context.AddTest("Update", testDPointUpdate, "DPoint");

    // Matrix Tests
    // Matrix Creation
    context.AddTest("construct_default", TestMatrix::construct_default, "Matrix");
    context.AddTest("construct_size", TestMatrix::construct_size, "Matrix");
    context.AddTest("construct_initialvalue", TestMatrix::construct_initialvalue, "Matrix");
    context.AddTest("construct_initializerlist", TestMatrix::construct_initializerlist, "Matrix");
    context.AddTest("construct_vector", TestMatrix::construct_vector, "Matrix");
    context.AddTest("construct_copy", TestMatrix::construct_copy, "Matrix");
    context.AddTest("construct_move", TestMatrix::construct_move, "Matrix");
    context.AddTest("operator_assign", TestMatrix::operator_assign, "Matrix");
    // Comparison operators
    context.AddTest("operator_equal", TestMatrix::operator_equal, "Matrix");
    context.AddTest("operator_notequal", TestMatrix::operator_notequal, "Matrix");
    context.AddTest("issquare", TestMatrix::issquare, "Matrix");
    // Basic operations
    context.AddTest("rows", TestMatrix::rows, "Matrix");
    context.AddTest("cols", TestMatrix::cols, "Matrix");
    context.AddTest("indexer", TestMatrix::indexer, "Matrix");
    context.AddTest("indexer_const", TestMatrix::indexer_const, "Matrix");
    context.AddTest("at", TestMatrix::at, "Matrix");
    context.AddTest("col_get", TestMatrix::col_get, "Matrix");
    context.AddTest("col_setmatrix", TestMatrix::col_setmatrix, "Matrix");
    context.AddTest("col_setvector", TestMatrix::col_setvector, "Matrix");
    context.AddTest("row_get", TestMatrix::row_get, "Matrix");
    context.AddTest("row_setmatrix", TestMatrix::row_setmatrix, "Matrix");
    context.AddTest("row_setvector", TestMatrix::row_setvector, "Matrix");
    context.AddTest("operator_vector", TestMatrix::operator_vector, "Matrix");
    context.AddTest("resize", TestMatrix::resize, "Matrix");
    // Arithmetic operations
    context.AddTest("add_matrix", TestMatrix::add_matrix, "Matrix");
    context.AddTest("add_scalar", TestMatrix::add_scalar, "Matrix");
    context.AddTest("subtract_matrix", TestMatrix::subtract_matrix, "Matrix");
    context.AddTest("subtract_salar", TestMatrix::subtract_salar, "Matrix");
    context.AddTest("multiply_matrix", TestMatrix::multiply_matrix, "Matrix");
    context.AddTest("multiply_scalar", TestMatrix::multiply_scalar, "Matrix");
    context.AddTest("divide_scalar", TestMatrix::divide_scalar, "Matrix");
    // Complex operations
    context.AddTest("adjoint", TestMatrix::adjoint, "Matrix");
    context.AddTest("cofactors", TestMatrix::cofactors, "Matrix");
    context.AddTest("determinant", TestMatrix::determinant, "Matrix");
    context.AddTest("inverse", TestMatrix::inverse, "Matrix");
    context.AddTest("minors", TestMatrix::minors, "Matrix");
    context.AddTest("submatrix", TestMatrix::submatrix, "Matrix");
    context.AddTest("transpose", TestMatrix::transpose, "Matrix");
    // Special operations
    context.AddTest("cholesky", TestMatrix::cholesky, "Matrix");
    context.AddTest("weightedmean", TestMatrix::weightedmean, "Matrix");
    context.AddTest("weightedcovariance", TestMatrix::weightedcovariance, "Matrix");

    // Model Tests
    context.AddTest("Tank Initialization", testTankInitialize, "Model Tank");
    context.AddTest("Tank State Eqn", testTankStateEqn, "Model Tank");
    context.AddTest("Tank Output Eqn", testTankOutputEqn, "Model Tank");

    context.AddTest("Battery Set Parameters", testBatterySetParameters, "Model Battery");
    context.AddTest("Battery Initialization", testBatteryInitialization, "Model Battery");
    context.AddTest("Battery State Eqn", testBatteryStateEqn, "Model Battery");
    context.AddTest("Battery Output Eqn", testBatteryOutputEqn, "Model Battery");
    context.AddTest("Battery Threshold Eqn", testBatteryThresholdEqn, "Model Battery");
    context.AddTest("Battery Input Eqn", testBatteryInputEqn, "Model Battery");
    context.AddTest("Battery Predicted Output Eqn", testBatteryPredictedOutputEqn, "Model Battery");

    // Observer Tests
    context.AddCategoryInitializer("Observer", observerTestsInit);
    // UKF Tank tests
    context.AddTest("UKF Initialize for Tank", testUKFTankInitialize, "Observer");
    context.AddTest("UKF Step for Tank", testUKFTankStep, "Observer");
    context.AddTest("UKF Tank Get Inputs", testUKFTankGetInputs, "Observer");

    // UKF Battery tests
    context.AddTest("UKF Battery Construction from ConfigMap", testUKFBatteryFromConfig, "Observer");
    context.AddTest("UKF Initialization for Battery", testUKFBatteryInitialize, "Observer");
    context.AddTest("UKF Step for Battery", testUKFBatteryStep, "Observer");

/*    // PF Battery tests
    context.AddTest("PF Battery Construction from ConfigMap", testPFBatteryFromConfig, "Observer");
    context.AddTest("PF Initialization for Battery", testPFBatteryInitialize, "Observer");
    context.AddTest("PF Step for Battery", testPFBatteryStep, "Observer"); */

    // PEvent Tests
    context.AddTest("Initialization", testPEventInit, "PEvent");
    context.AddTest("Meta Data", testPEventMeta, "PEvent");
    context.AddTest("Update", testPEventUpdate, "PEvent");

    // ProgData Tests
    context.AddTest("Prog Data", progDataTest, "ProgData");
    context.AddTest("Prog Data Copy", progDataCopyTest, "ProgData");

    // Thread Tests
    context.AddTest("treadctrl", tctrltests, "Thread");
    context.AddTest("Exception", exceptiontest, "Thread");

    // Predictor Tests
    context.AddCategoryInitializer("Predictor", predictorTestInit);
    context.AddTest("Monte Carlo Predictor Configuration for Battery", testMonteCarloBatteryConfig, "Predictor");
    context.AddTest("Monte Carlo Prediction for Battery", testMonteCarloBatteryPredict, "Predictor");

    // TCP Tests
   context.AddTest("testConnect",testConnect, "TCP");
   context.AddTest("testSend",testSend, "TCP");
   context.AddTest("testReceive",testReceive, "TCP");

   // UDP Tests
   context.AddTest("testConnect_UDP", testConnect_UDP, "UDP");
   context.AddTest("testReceive_UDP", testReceive_UDP, "UDP");

 //  context.AddTest("Recieve Buffer Size",testRecieveBufferSize,"TCP");
 //  context.AddTest("Send Buffer Size",testSendBufferSize,"TCP");
 //  context.AddTest("Connect",testConnect,"TCP");
   //    context.AddTest("Send and Receive",testSendAndReceive,"TCP");
//   context.AddTest("Test", testTest, "TCP");
 //  context.AddTest("Receive", testReceive, "TCP");

    int result = context.Execute();
    std::ofstream junit("testresults/support.xml");
    context.WriteJUnit(junit);
    return result;
}
