import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.UUID;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;;


//TODO javadoc DataLoader
public class DataLoader extends DataConstants {
	JSONParser parser = new JSONParser();
	static FileReader reader;

	/**
	 * 
	 * @return ArrayList of type account populated by account.son
	 */
	public static ArrayList<Account> getAccts() {
		ArrayList<Account> accts = new ArrayList<Account>();

		try {
			reader = new FileReader(ACCOUNTS_FILE_NAME);
			JSONArray acctsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < acctsJSON.size(); i++) {
				JSONObject acctJSON = (JSONObject) acctsJSON.get(i);
				UUID id = UUID.fromString((String)acctJSON.get(ID));
				AcctType acct_type = AcctType.valueOf((String) acctJSON.get(ACCT_TYPE));
				String username = (String) acctJSON.get(USERNAME);
				String password = (String) acctJSON.get(PASSWORD);
				String firstName = (String) acctJSON.get(FIRSTNAME);
				String lastName = (String) acctJSON.get(LASTNAME);
				String email = (String) acctJSON.get(EMAIL);
				String phoneNum = (String) acctJSON.get(PHONENUMBER);
				String dob = (String) acctJSON.get(DOB);
				String company = (String) acctJSON.get(COMPANY);

				if (acct_type == AcctType.USER)
					accts.add(new User(id, username, password, firstName, lastName, email, phoneNum, dob));
				if (acct_type == AcctType.ADMIN)
					accts.add(new Admin(username, password, company));
			}
		}

		catch (Exception e) {
			e.printStackTrace();
		}

		return accts;
	}

	/**
	 * 
	 * @return ArrayList of type Car populated by car.json
	 */
	public static ArrayList<Car> getCars() {
		ArrayList<Car> cars = new ArrayList<Car>();

		try {
			reader = new FileReader(CAR_FILE_NAME);
			JSONArray carsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < carsJSON.size(); i++) {
				JSONObject vehicleJSON = (JSONObject) carsJSON.get(i);
				UUID id = UUID.fromString((String) vehicleJSON.get(CAR_ID));
				String make = (String) vehicleJSON.get(CAR_MAKE);
				String model = (String) vehicleJSON.get(CAR_MODEL);
				int seats = ((Long) vehicleJSON.get(CAR_SEATS)).intValue();
				int year = ((Long) vehicleJSON.get(CAR_YEAR)).intValue();
				String type = ((String) vehicleJSON.get(CAR_TYPE));
				String color = ((String) vehicleJSON.get(CAR_COLOR));
				Boolean availability = (Boolean) vehicleJSON.get(CAR_AVAILABLE);

				cars.add(new Car(id, make, model, type, year, seats, color, availability));

			}
		}

		catch (Exception e) {
			e.printStackTrace();
		}

		return cars;
	}

	/**
	 * 
	 * @return ArrayList of type Car populated by hotel.json
	 */
	public static ArrayList<Hotel> getHotels() {
		ArrayList<Hotel> hotels = new ArrayList<Hotel>();

		try {
			reader = new FileReader(HOTEL_FILE_NAME);

			JSONArray hotelsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < hotelsJSON.size(); i++) {
				JSONObject hotelJSON = (JSONObject) hotelsJSON.get(i);
				UUID id = UUID.fromString((String) hotelJSON.get(HOTEL_ID));
				String country = (String) hotelJSON.get(HOTEL_COUNTRY);
				String city = (String) hotelJSON.get(HOTEL_CITY);
				String address = (String) hotelJSON.get(HOTEL_ADDRESS);
				int zip = ((Long) hotelJSON.get(HOTEL_ZIP)).intValue();
				ArrayList<Room> rooms = new ArrayList<Room>();

				hotels.add(new Hotel(id, country, city, address, zip, rooms));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return hotels;
	}

	/**
	 * 
	 * @return ArrayList of type Flight populated by flight json
	 */
	public static ArrayList<Flight> getFlights() {
		ArrayList<Flight> flights = new ArrayList<Flight>();

		try {
			reader = new FileReader(FLIGHT_FILE_NAME);
			JSONArray flightsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < flightsJSON.size(); i++) {
				JSONObject flightJSON = (JSONObject) flightsJSON.get(i);
				UUID id = UUID.fromString((String) flightJSON.get(FLIGHT_ID));
				SimpleDateFormat dateFormat = new SimpleDateFormat("EEE MMM dd HH:mm:ss z yyyy");
		
				Date deptTime = dateFormat.parse((String)flightJSON.get(FLIGHT_DEPT_TIME));
				String deptCode = (String) flightJSON.get(FLIGHT_DEPT_AIRP_CODE);
				String deptGate = (String) flightJSON.get(FLIGHT_DEPT_GATE);
				Cities deptCity = Cities.valueOf(((String) flightJSON.get(FLIGHT_DEPT_CITY)).toUpperCase());
				Country deptCountry = Country.searchForCountry((flightJSON.get(FLIGHT_DEPT_COUNTRY).toString()).toUpperCase());
				Date arrTime = dateFormat.parse((String)flightJSON.get(FLIGHT_ARR_TIME));
				String arrCode = (String) flightJSON.get(FLIGHT_ARR_AIRP_CODE);
				String arrGate = (String) flightJSON.get(FLIGHT_ARR_GATE);
				Cities arrCity = Cities.valueOf(((String) flightJSON.get(FLIGHT_ARR_CITY)).toUpperCase());
				Country arrCountry = Country.searchForCountry(((String)flightJSON.get(FLIGHT_ARR_COUNTRY)).toUpperCase());
				Airlines airline = Airlines.valueOf(((String)flightJSON.get(FLIGHT_AIRLINE)).toUpperCase());
				String flightNum = (String) flightJSON.get(FLIGHT_NUM);
				
				Flight newFlight = new Flight(id, deptTime, deptCode, deptGate, deptCity, deptCountry, arrTime, arrCode, arrGate, arrCity, arrCountry, airline, flightNum);
				flights.add(newFlight);
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

		return flights;
	}

	/**
	 * 
	 * @return
	 */
	public static ArrayList<Room> getRooms() {
		ArrayList<Room> rooms = new ArrayList<Room>();

		try {
			reader = new FileReader(ROOM_FILE_NAME);
			JSONArray roomsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < roomsJSON.size(); i++) {
				JSONObject roomJSON = (JSONObject) roomsJSON.get(i);
				UUID id = UUID.fromString((String) roomJSON.get(ROOM_ID));
				UUID hotelId = UUID.fromString((String) roomJSON.get(ROOM_HOTEL_ID));
				Hotel hotel = HotelList.getInstance().searchByUUID(hotelId);
				int numBeds = ((Long) roomJSON.get(ROOM_NUM_BEDS)).intValue();
				boolean availability = (boolean) roomJSON.get(ROOM_AVAILABILITY);
				RoomType suiteType = RoomType.valueOf(((String) roomJSON.get(ROOM_SUITE_TYPE)).toUpperCase());

				rooms.add(new Room(id, hotel, numBeds, availability, suiteType));
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

		return rooms;
	}

	public ArrayList<Room> getRoomsByHotel(Hotel hotel) {
		return RoomList.getInstance().searchByHotelUUID(hotel.getID());
	}
	public static ArrayList<Booking> getBookings() {
		ArrayList<Booking> bookings = new ArrayList<Booking>();

		try {
			reader = new FileReader(HOTEL_FILE_NAME);

			JSONArray bookingsJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < bookingsJSON.size(); i++) {
				JSONObject bookingJSON = (JSONObject) bookingsJSON.get(i);
				UUID id = UUID.fromString((String) bookingJSON.get(BOOKING_ID));
				UUID userId = (UUID) bookingJSON.get(BOOKING_USER_ID);
				User user = (User)AccountList.getInstance().searchByUUID(userId);
				UUID flightId = (UUID) bookingJSON.get(BOOKING_FLIGHT_ID);
				Flight flight = FlightList.getInstance().searchByUUID(flightId);
				UUID hotelId = (UUID) bookingJSON.get(BOOKING_HOTEL_ID);
				Hotel hotel = HotelList.getInstance().searchByUUID(hotelId);
				UUID roomId = (UUID) bookingJSON.get(BOOKING_ROOM_ID);
				Room room = RoomList.getInstance().searchByUUID(roomId);
				UUID carId = (UUID) bookingJSON.get(BOOKING_CAR_ID);
				Car car = CarList.getInstance().searchByUUID(carId);

				bookings.add(new Booking(id, user, flight, hotel, room, car));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return bookings;
	}

	public static ArrayList<Country> getCountries() {
		ArrayList<Country> countries = new ArrayList<Country>();

		try {
			reader = new FileReader(COUNTRY_FILE_NAME);

			JSONArray countriesCopyJSON = (JSONArray) new JSONParser().parse(reader);

			for (int i = 0; i < countriesCopyJSON.size(); i++) {

				JSONObject countryJSON = (JSONObject) countriesCopyJSON.get(i);
				Country.Countries name = Country.Countries.valueOf(((String) countryJSON.get(NAME)).toUpperCase());
				JSONArray citiesJSON = (JSONArray) countryJSON.get(CITIES);
				ArrayList<Cities> cities = new ArrayList<>();

				for (int j = 0; j < citiesJSON.size(); j++) {
					String cityText = citiesJSON.get(j).toString();
					Cities city = Cities.valueOf(cityText.toUpperCase());
					cities.add(city);
				}
				
				
				
				countries.add(new Country(name, cities));
			}
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	return countries;
	}
}