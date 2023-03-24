defmodule Cs491Hm1.OfficeAssets do
  @moduledoc """
  The OfficeAssets context.
  """

  import Ecto.Query, warn: false
  alias Cs491Hm1.Repo

  alias Cs491Hm1.OfficeAssets.Printer

  @doc """
  Returns the list of printer.

  ## Examples

      iex> list_printer()
      [%Printer{}, ...]

  """
  def list_printer do
    Repo.all(Printer)
  end

  @doc """
  Gets a single printer.

  Raises `Ecto.NoResultsError` if the Printer does not exist.

  ## Examples

      iex> get_printer!(123)
      %Printer{}

      iex> get_printer!(456)
      ** (Ecto.NoResultsError)

  """
  def get_printer!(id), do: Repo.get!(Printer, id)

  @doc """
  Creates a printer.

  ## Examples

      iex> create_printer(%{field: value})
      {:ok, %Printer{}}

      iex> create_printer(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_printer(attrs \\ %{}) do
    %Printer{}
    |> Printer.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a printer.

  ## Examples

      iex> update_printer(printer, %{field: new_value})
      {:ok, %Printer{}}

      iex> update_printer(printer, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_printer(%Printer{} = printer, attrs) do
    printer
    |> Printer.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a printer.

  ## Examples

      iex> delete_printer(printer)
      {:ok, %Printer{}}

      iex> delete_printer(printer)
      {:error, %Ecto.Changeset{}}

  """
  def delete_printer(%Printer{} = printer) do
    Repo.delete(printer)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking printer changes.

  ## Examples

      iex> change_printer(printer)
      %Ecto.Changeset{data: %Printer{}}

  """
  def change_printer(%Printer{} = printer, attrs \\ %{}) do
    Printer.changeset(printer, attrs)
  end

  alias Cs491Hm1.OfficeAssets.Computer

  @doc """
  Returns the list of computer.

  ## Examples

      iex> list_computer()
      [%Computer{}, ...]

  """
  def list_computer do
    Repo.all(Computer)
  end

  @doc """
  Gets a single computer.

  Raises `Ecto.NoResultsError` if the Computer does not exist.

  ## Examples

      iex> get_computer!(123)
      %Computer{}

      iex> get_computer!(456)
      ** (Ecto.NoResultsError)

  """
  def get_computer!(id), do: Repo.get!(Computer, id)

  @doc """
  Creates a computer.

  ## Examples

      iex> create_computer(%{field: value})
      {:ok, %Computer{}}

      iex> create_computer(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_computer(attrs \\ %{}) do
    %Computer{}
    |> Computer.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a computer.

  ## Examples

      iex> update_computer(computer, %{field: new_value})
      {:ok, %Computer{}}

      iex> update_computer(computer, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_computer(%Computer{} = computer, attrs) do
    computer
    |> Computer.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a computer.

  ## Examples

      iex> delete_computer(computer)
      {:ok, %Computer{}}

      iex> delete_computer(computer)
      {:error, %Ecto.Changeset{}}

  """
  def delete_computer(%Computer{} = computer) do
    Repo.delete(computer)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking computer changes.

  ## Examples

      iex> change_computer(computer)
      %Ecto.Changeset{data: %Computer{}}

  """
  def change_computer(%Computer{} = computer, attrs \\ %{}) do
    Computer.changeset(computer, attrs)
  end
end
